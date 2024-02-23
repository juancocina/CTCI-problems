/*
    1.3 URLify: Write a method to replace all spaces in a string
    with '%20'. You may assume that the string has sufficient space
    at the end to hold the additional characters, & that you are given the
    "true" lenght of the string.
*/
#include <string>
#include <iostream>
#include <vector>
#include <utility> //for pair & make_pair
//prototype
int charCount(std::string s, int start, int finish, char target);

// My solution
void URLify(std::string s, int trueLength){
    std::string newString;

    for(int i = 0; i < trueLength; i++){
        if(s[i] != ' ') newString += s[i];
        else newString += "%20";
    }
    std::cout << newString << std::endl;
} // O(n) space, O(n) time
/*
    We have to go through every character in S up to trueLength (n) &
    we have to copy each char over to a new string + add %20
*/

// CTCI Solution (Java -> C++)
void URLifyByTheBook(std::string s, int trueLength){
    int numberOfSpaces = charCount(s, 0, trueLength, ' ');
    // I know I could just use s.length/size, but i wanna translate the java
    int newIndex = trueLength - 1 + numberOfSpaces * 2;

    // I'm not going to translate line 7 over because 
    // this solution is using a string not a char array
    for(int oldIndex = trueLength -1; oldIndex > 0; oldIndex--){
        if(s[oldIndex] == ' '){
            s[newIndex] = '0';
            s[newIndex - 1] = '2';
            s[newIndex - 2] = '%';
            newIndex -= 3;
        }else{
            s[newIndex] = s[oldIndex];
            newIndex--;
        }
    }

    std::cout << s << std::endl;
} // O(1) space, O(n) time where n is the length of the string
/*
    We have to go through the string twice
        Once to count the spaces
        Once to modify the string
    The space remains the same since the characters are only shifted around
*/

// Helper function to count the spaces
int charCount(std::string s, int start, int finish, char target){
    int counter = 0;
    for(int i = 0; i < finish; i++){
        if(s[i] == target) counter++;
    }

    return counter;
}

int main() {
    //std::string test = "Mr John Smith    ";

    std::vector<std::pair<std::string, int>> tests;
    tests.push_back(std::make_pair("Mr John Smith    ", 13));
    tests.push_back(std::make_pair("This is a test      ", 14));
    tests.push_back(std::make_pair("God is dead    ", 11));
    tests.push_back(std::make_pair("This is a longer input        ", 22));
    for(const auto &test: tests){
        //URLify(test.first, test.second);
        URLifyByTheBook(test.first, test.second);
    }

    return 0;
}

/*
    Before I code up the books solution,
    One thing that I didn't fully understand about this problem were the hints
    Hint 1 was to walk backwards through the string
    Hint 2 was to count the spaces

    Why? When I could just use += to insert the "%20" as I moved forward 
    through the string
...
    Once I took a look at the books solution and their explanation (strings
    in java are immutable), I understood why they chose to do it that way.

    So I decided it would be very important for me to learn that technique as
    well.
    My tests do not include all ASCII values, and are modeled after the example
    given in the book.

    ...
    I ended up just translating the books java to c++
    I may not be an expert, but I would hope that the space trade off in my 
    solution is worth it for cleaner code
*/