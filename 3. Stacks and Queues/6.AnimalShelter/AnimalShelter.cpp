/*
    3.6 Animal Shelter: An animal shelter, which holds only dogs and cats, 
    operates on a strictly "first in, first out" basis. People must adopt either the 
    "oldest" (based on arrival time) of all animals at the shelter, or they can select
    whether they would prefer a dog or cat ( and will receive the oldest animal of
    that type). They cannot select which specific animal they would like.
    Create the data astructures to maintain this system and implement operations
    such as: enqueue, dequeueAny, dequeueDog, and dequeueCat.
    You must use the built-in LinkedList Data Structure.

    *I do want do note that I am using the STD Linked List not the one from the CTCI book

*/

#include<iostream>
#include<list>
#include<string>
#include<chrono>
#include<ctime>
#include<thread>

class Animal {
    public:
        std::string name;
        std::string typeOfAnimal;
        std::time_t arrivalTime;

        Animal(std::string n, std::string ToA){
            this->typeOfAnimal = ToA;
            this->name = n;
            this->arrivalTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        }
};

class AnimalShelter {
    public:
        std::list<Animal> cats;
        std::list<Animal> dogs;

    public:
        void enqueue(Animal a);
        void dequeueAny();
        void dequeueCat();
        void dequeueDog();
        void print();
};
//=============================================================================

void AnimalShelter::enqueue(Animal a)
{
    if(a.typeOfAnimal == "cat" || a.typeOfAnimal == "Cat")
        cats.push_back(a);
    else if(a.typeOfAnimal == "dog" || a.typeOfAnimal == "Dog")
        dogs.push_back(a);
    else std::cout << "Not a dog or cat\n";

    return;
}

void AnimalShelter::dequeueAny() {
    if(dogs.empty() && cats.empty()) {
        std::cout << "No pets available..." << std::endl;
        return;
    }
    else if(dogs.empty() && !cats.empty()) cats.pop_front(); // only cats available
    else if(!dogs.empty() && cats.empty()) dogs.pop_front(); // only dogs available
    else {
        if(cats.front().arrivalTime < dogs.front().arrivalTime)
            cats.pop_front();
        else 
            dogs.pop_front();
    }
    return;
}

void AnimalShelter::dequeueCat() {
    if(cats.empty()) {
        std::cout << "No cats available..." << std::endl;
        return;
    }
    cats.pop_front();
    return;
}

void AnimalShelter::dequeueDog() {
    if(dogs.empty()){
        std::cout << "No dogs available..." << std::endl;
        return;
    }
    dogs.pop_front();
    return;
}

void AnimalShelter::print() {
    std::cout << "Cats" << std::endl;
    for(std::list<Animal>::iterator it = cats.begin(); it != cats.end(); it++)
        std::cout << it->name << " " << std::ctime(&it->arrivalTime) << " " << it->typeOfAnimal << std::endl;
    
    std::cout << "Dogs" << std::endl;
    for(std::list<Animal>::iterator it = dogs.begin(); it != dogs.end(); it++)
        std::cout << it->name << " " << std::ctime(&it->arrivalTime) << " " << it->typeOfAnimal << std::endl;
    
    std::cout << std::endl;

    return;
}
//=================================================

int main() {
    AnimalShelter mainShelter;
    
    Animal a = Animal("Buster", "Cat");
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    mainShelter.enqueue(a);

    Animal b = Animal("Boxer", "dog");
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    mainShelter.enqueue(b);

    Animal c = Animal("Joker", "dog");
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    mainShelter.enqueue(c);

    mainShelter.enqueue(Animal("TacoBell", "cat"));
    std::this_thread::sleep_for(std::chrono::milliseconds(400));

    mainShelter.enqueue(Animal("Monster", "Dog"));
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    
    mainShelter.enqueue(Animal("Cookie", "Dog"));
    std::this_thread::sleep_for(std::chrono::milliseconds(400));

    mainShelter.enqueue(Animal("The Void", "Cat"));
    std::this_thread::sleep_for(std::chrono::milliseconds(400));

    mainShelter.print();

    mainShelter.dequeueCat();
    mainShelter.dequeueAny();
    mainShelter.dequeueDog();

    std::cout << "After popping" << std::endl;
    mainShelter.print();

    return 0;
}

/*
    Time Complexity for this shouldn't be too bad
    Print is going ot be O(N), but since that isn't part of the original question
    I won't count it

    Time should be constant
    Space is linear

    One thing that I would like to point out, is that
    If we were using this in a real world scenario,
    I would likely change void to Animal on functions dequeueAny, dequeueCat, dequeueDog
*/