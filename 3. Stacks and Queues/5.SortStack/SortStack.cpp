/*
    3.5 Sort Stack: Write a program to sort a stack such that the smallest
    items are on the top. YOu can use an additional temporary stack, 
    but you may not copy the elemnts into any other data structure (such as an array).
    The stack supports the following operations: push, pop, peek, and isEmpty.
*/

#include<iostream>
#include<stack>

class MyStack {
    private:
        std::stack<int> st;

    public:
        void push(int d);
        void pop();
        int peek();
        bool isEmpty();
};

void MyStack::push(int d) {
    if(st.empty()){
        st.push(d);
        return;
    }
    std::stack<int> temp;
    
    // while our incoming data is greater than the stacks top data
    while(!st.empty() && d > st.top()){ // move all nodes less than our incoming data onto the temp stack
        temp.push(st.top());
        temp.pop();
    }

    st.push(d); // push our incoming data into our main stack

    while(!temp.empty()){ // move back all our smaller data onto the stack
        st.push(temp.top());
        temp.pop();
    }
    return;
}

void MyStack::pop() {
    if(st.empty()) return;

    st.pop();
}

int MyStack::peek() {
    if(st.empty()){
        std::cout << "Stack is empty" << std::endl;
        return 404;
    }
    return st.top();
}

bool MyStack::isEmpty() {
    return st.empty();
}

int main() {
    MyStack s;

    s.push(5);
    std::cout << s.peek() << std::endl;
    s.push(5);
    std::cout << s.peek() << std::endl;

    s.push(10);
    std::cout << s.peek() << std::endl;
    s.push(9);
    std::cout << s.peek() << std::endl;

    s.push(1);
    std::cout << s.peek() << std::endl;
    s.push(2);
    std::cout << s.peek() << std::endl;

    s.pop();

    return 0;
}