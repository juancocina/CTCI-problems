#include "Stack.h"
#include <iostream>

Stack::Stack() {
    top = nullptr;
}

// creating the stack 
Stack s;

void Stack::push(int data){
    Node* n = new Node();
    
    //precautionary check for stack overflow
    if(!n){
        cout << "StackOverflow";
        exit(1);
    }

    n->data = data;
    n->next = s.top;
    if(isEmpty()) {
        n->subMin = data;
    } else if(data < s.top->subMin) {
        n->subMin = data;
    } else {
        n->subMin = s.top->subMin;
    }
    s.top = n;
}

void Stack::pop() {
    Node* n;
    if(s.top == nullptr) {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }else {
        n = s.top;
        s.top = s.top->next;

        free(n);
    }
}

int Stack::peek() {
    if(!isEmpty()) return s.top->data;
    
    exit(1);
}

int Stack::min() {
    if(!isEmpty()) return s.top->subMin;

    exit(1);
}


void Stack::display() {
    Node* n;

    if(s.top == nullptr){
        cout << "\nStack Underflow";
        exit(1);
    }else {
        n = s.top;
        while(n != nullptr){
            cout << n->data;
            n = n->next;
            if(n != nullptr) cout << "->";
        }
    }
}

// driver function, will be used to test
int main() {
    s.push(3);
    s.push(5);
    s.push(6);
    s.push(1);
    s.push(4);
    s.push(7);
    s.push(0);
    s.push(9);

    s.display();

    cout << "\nTop Element: " << s.peek() << endl;
    cout << "Minimum Element: " << s.min() << endl;

    //pop twice
    s.pop();
    s.pop();

    s.display();


    cout << "\nTop Element: " << s.peek() << endl;
    cout << "Minimum Element: " << s.min() << endl;
    
    return 0;
}