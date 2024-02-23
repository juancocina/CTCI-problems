#include "MultiStack.h"

MultiStack::MultiStack(int stackCapacity) { // constructors don't have a return type
    this->stackCapacity = stackCapacity;
    stackArray = new int[numOfStack * stackCapacity]();
    stackCapacityUsed = new int[numOfStack]();
} // I think this constructor is similar to StackInfo in the book

MultiStack::~MultiStack() {
    delete[] stackArray;
    delete[] stackCapacityUsed; // I'm wondering where this is used
}

void MultiStack::push(int stackNum, int value) {
    if(isFull(stackNum)) std::cout << "Stack" << stackNum << "is Full...\n";
    else {
        stackCapacityUsed[stackNum]++; // increase the tracked capacity at the given stack
        stackArray[indexOfTop(stackNum)] = value; // place value inside of array, in the given stack (stackNum) using the index of the top of THAT stack
    }
}

void MultiStack::pop(int stackNum) {
    if(isEmpty(stackNum)) std::cout << "Stack " << stackNum << " is Empty...\n";
    else {
        int topIndex = indexOfTop(stackNum); // get the index of the stack to be popped
        stackArray[topIndex] = 0; // set the index to 0
        stackCapacityUsed[stackNum]--; // reduce the tracked capacity at the given stack
    }
} // as opposed to the book, this pop does not return the value, just pops it.


int MultiStack::top(int stackNum) const { // why is this const?
    if(isEmpty(stackNum)) {
        std::cout << "Stack " << stackNum << " is Empty...\n";
        exit(1); // or throw exception
    }
    else {
        return stackArray[indexOfTop(stackNum)]; //indexOfTop seems like a very vital function
    }
}

bool MultiStack::isEmpty(int stackNum) const { return stackCapacityUsed[stackNum] == 0; }
bool MultiStack::isFull(int stackNum)  const { return stackCapacityUsed[stackNum] == stackCapacity; }

int MultiStack::indexOfTop(int stackNum) const {
    int startIndex = stackNum * stackCapacity;
    int capacity = stackCapacityUsed[stackNum];
    return (startIndex + capacity -1);
}