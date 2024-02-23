#include "plates.h"

Stack::Stack() {
    top = nullptr;
}

void Stack::push(int data) {
    Node* n = new Node();
    if(!n) {
        cout << "StackOverFlow";
        exit(1);
    }

    n->data = data;
    n->next = top;
    top = n;

    capacity++;
}

void Stack::pop() {
    Node* n;
    if(top == nullptr){
        cout << "\nStack Underflow at pop" << endl;
        exit(1);
    }else {
        n = top;
        top = top->next;

        free(n);
    }
    capacity--;
}

int Stack::peek() {
    if(top != nullptr) return top->data;

    exit(1);
}

void Stack::display(){
    Node* n;

    if(top == nullptr){
        cout << "\nStack Underflow at display";
        exit(1);
    }else{
        n = top;
        while(n != nullptr){
            cout << n->data;
            n = n->next;
            if(n != nullptr) cout << "->";
        }
    }
    cout << endl;
}
//===================================================================
vector<Stack*> v;
PlateStack::PlateStack(){
    v.push_back(new Stack());
    stacks++; //why ++ instead of stack 0? well we have one stack, so we'll leave it like that right now
    curStack = 0; //0 to access the first stack
}

//=================================
void PlateStack::push(int data) {
    if(PlateStack::isFull(curStack)){
        newStack();
        curStack++;
    }
    if(curStack <= stacks-1) //if we actually have a stack to push onto
        v[curStack]->push(data);
    else exit(1);
}

void PlateStack::pop() {
    if(PlateStack::isEmpty(curStack)){
        curStack--;
    }
    if(curStack <= stacks-1)
        v[curStack]->pop();
    else exit(1);
}

void PlateStack::top() {
    cout << v[curStack]->peek() << endl;
}

//=================================
bool PlateStack::isEmpty(int curStack) const { 
    if(v[curStack]->capacity == 0) return true;

    return false;
}
bool PlateStack::isFull(int curStack) const { 
    if(v[curStack]->capacity == 10) return true;

    return false;
}

//=================================
void PlateStack::newStack() {
    cout << "\n creating new stack...\n" << endl;
    v.push_back(new Stack());
    stacks++;
}

void PlateStack::removeStack(){
    cout << " removing stack...\n";
    v.pop_back();
    stacks--;
}

void PlateStack::print(){
    for(int i = 0; i < stacks; i++){
        if(v[i]->capacity != 0) {
            cout << endl;
            v[i]->display();
        }
    }
}

void PlateStack::popAt(int index) {
    if(index <= stacks-1 && !PlateStack::isEmpty(index)) {
        v[index]->pop();
        cout << endl;
    }else {
        cout << "No index exists..." << endl;
    }
}

//driver function, will be used to test
PlateStack s;
int main() {
    s.push(3);
    s.push(5);
    s.push(6);
    s.push(1);
    s.push(4);
    s.push(7);
    s.push(0);
    s.push(9);
    s.push(1);
    s.push(10);

    cout << "\nprinting all elements" << endl;
    s.print();

    cout << "\npopping two.." << endl;
    //pop twice
    s.pop();
    s.pop();
    s.print();

    cout << "\n\npushing past threshold of 10 nodes per stack...\n";
    //push past threshold
    s.push(1);
    s.push(4);
    s.push(7);
    s.push(0);
    s.print();

    cout << "\nremoving nodes...\n";
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.print();

    cout << "\ntesting top/peek..\n";
    s.top();

    cout << "\ntesting popAt..\n";
    s.top();
    s.popAt(0); //the zero stack is our first stack
    s.top();
    //going to push past threshold again and then remove from 0 stack again
    s.push(1);
    s.push(4);
    s.push(7);
    s.push(0);
    s.push(3);

    s.push(5);
    s.push(6);
    s.push(1);
    s.push(4);
    s.push(7);
    s.push(0);
    s.print();

    
    s.popAt(0);
    s.popAt(0);
    s.print();
    s.popAt(1);
    s.print();
    return 0;
}

/*
    Alright.. this is a post-completion comment section

    I had opened up this problem on wednesday, maybe tried it for an hour.
    I just planted a seed, but didn't really code anything.

    I tried this again on the following sunday from about 4-6, again, didn't code much
    But, on paper, I drew out a bit of a plan on what would work and what wouldn't.

    I thought about doing a 2d array where I would push a vector of size 10 into a vector.
    A little bit of research online quickly showed me that it would be horrible for memory management.
    I think my solution still isn't THE best, but it works. I know that I could learn a thing or two
    about memory management, especially destructors. That can be a goal of mine.

    This problem really helped me understand classes and encapsulation. As well as using multiple classes
    to come to a solution, building off one another.

    I still think I should take a look at the books solution to see what I could do better, but
    I'm glad I was able to finish this one.
*/