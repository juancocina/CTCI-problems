#include "MyQueue.h"

MyQueue::MyQueue(){
    //not sure if i need to do anything here       
}

void MyQueue::push(int data){
    if(s1.empty() && !s2.empty()) {
        transfer(s2, s1); // transfer from s2 to s1
    }
    s1.push(data);
}

void MyQueue::pop(){
    if(s2.empty() && !s1.empty()){
        transfer(s1, s2); // transfer from s1 to s2
    } 
    else if(s2.empty() && s1.empty()) cout << "\nNothing to pop...\n";
    s2.pop();
    
}

void MyQueue::print() {
    //need to transfer to the order of a queue with a temp stack, as to not disturb our data
    stack<int> t;
    if(s2.empty() && !s1.empty()){
        while(!s1.empty()){
            t.push(s1.top());
            s2.push(s1.top());
            s1.pop();
        }
        transfer(s2, s1); //move everything back
        
    }
    else if(s2.empty() && s1.empty()) {
        cout << "\nNothing to print...\n";
        return;
    } else if(!s2.empty()){
        transfer(s2, s1); //prep the transfer
        while(!s1.empty()){
            t.push(s1.top());
            s2.push(s1.top());
            s1.pop();
        } //put everything back and use the dummy stack
    }

    while(!t.empty()){
        cout << t.top() << " ";
        t.pop();
    }

    cout << endl;
} //the reason I don't use transfer() here is because I need to make a duplicate of the data in the stacks
//but the result is duplicate code at 27-31 & 40-44

void MyQueue::transfer(stack<int>& n, stack<int>& m){ //from the left stack to the right stack
    if(n.empty()){
        cout << "\nNothing to transfer...\n";
        return;
    }else
        while(!n.empty()){
            m.push(n.top());
            n.pop();
        }
}



//driver function 
int main() {
    MyQueue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.print();
    //the queue order should be 1 2 3 4, but the stack is top->4 3 2 1 
    //pop order should be 1 2 3.. and print should display 2 3 4 
    q.pop();
    q.pop();
    q.print();

    //push again
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(7);
    q.push(6);
    q.push(4);
    q.push(3);
    q.print();

    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.print();

    return 0;
}

/*
    I will admit, I did take a shorcut here by using the C++ stack
    I definitely could've made my own class using Nodes as I have done in the previous 
    questions, but I didn't really want to do that.

    I think the real practice here was to simply create the logic behind 
    the queue implementation.
*/