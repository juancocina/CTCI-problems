/**
 * @file 2.kthElement.cpp
 * @author Juan Cocina (juancocina1337@gmail.com)
 * @brief 2.2 Return the Kth to last: Implement an algorithm to find the 
 *              kth to last element of a singly linked list.
 * @version 0.1
 * @date 2023-03-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node *next;

    //constructor
    Node (int value, Node *newNext = nullptr){
        data = value;
        next = newNext;
    }
};

void printList(Node *head){
    Node *ptr = head;
    while(ptr != nullptr){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
} //print list

Node* kElement(Node *head, int k) {
    Node *cur = head;
    Node *ptr = head;

    while(cur != nullptr){
        if(k == 0){
            ptr = ptr->next;
        }else {
            k--;
        }
        cur = cur->next;
    }
    return ptr;
} // Time O(n), space O(1);

int main(){
    Node *result;
    Node *newList = nullptr;
    vector<int> v = {6, 3, 4, 7, 8, 10, 12, 5, 1, 13, 24}; 
    //the constructor adds them from right 
    //to left but it still works
    for(auto a: v){
        newList = new Node(a, newList);
    }

    //looking for kth to last element
    printList(newList);
    result = kElement(newList, 4);
    cout << "\n" << result->data;
    return 0;
}

/*
    This one didn't take me too long
    That last hint really gave me the idea of how to tackle this problem with
    two pointers. 
    I didn't attempt a recursive solution simply because I'm not good at that 
    at the moment, hopefully later ill have the skills for that.

    Truthfully i don't know how i got this answer, but it looks like it works lol
*/