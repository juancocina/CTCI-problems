using namespace std;

//creating the Node class
class Node {
    public:
        int data;
        int subMin; //minimum for the substack below itself
        Node* next;
};

class Stack {
    // Node* top;
    public:
        Node* top;
        //constructor
        Stack();

        //push onto the stack
        void push(int data);
        
        //pop from the stack
        void pop();

        //grab the top of the stack
        int peek();

        //grab the minimum from the stack
        int min();

        //check if stack is empty
        bool isEmpty();

        //display the stack
        void display();

};