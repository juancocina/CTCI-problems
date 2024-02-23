#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

class Stack {
    public:
        Node* top;
        Node* next;

        Stack();

        void push(int data);
        void pop();
        int peek();

        void display();

        const int max = 10;
        int capacity;
};

class PlateStack: public Stack {
    public:
    //i think the constructor for this should call into stack to create a new stack
        PlateStack();
        //functions here will be push, pop, etc, as well as create new stack
        void push(int data);
        void pop();
        void top();

        bool isEmpty(int stackNum) const;
        bool isFull(int stackNum) const;

        void newStack();
        void removeStack();

        void print();
        void popAt(int index);
    //the private variables should keep track of the stacks, capacities, and current stack
    private: 
        int stacks = 0;
        int curStack;
    };