#include <stack>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class MyQueue {
    public:
        //constructor
        MyQueue();
        //destructor
        //~MyQueue();

        //push
        void push(int data);
        
        //pop
        void pop();

        //print
        void print();

        //transfer from stack to stack
        void transfer(stack<int>& n, stack<int>& m);
    private:
        stack<int> s1, s2;
};