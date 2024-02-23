/**
 * @file 1.RemoveDups.cpp
 * @author Juan Cocina (juancocina1337@gmail.com)
 * @brief 2.1 Remove Dups: Write code to remove duplicates from an
 *                         unsorted list. (I am assuming singly linked)
 *        - Follow up: How would you solve this problem if a temporary buffer
 *          is not allowed?
 * @version 0.1
 * @date 2023-03-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// basic implementation of a Node struct w/ constructor
struct Node {
    int data;
    Node *next;

    //constructor
    Node(int value, Node *newNext = nullptr){
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

//problem solution
void deleteDups(Node *head){
    unordered_set<int> s;
    Node *prev = nullptr;
    Node *cur = head;

    while(cur != nullptr){
        if(!s.count(cur->data)){ // if data not found
            s.insert(cur->data); // add data to set
            prev = cur;
        }
        else if(s.count(cur->data)){ // if found
            prev->next = cur->next; // move prev point to skip cur
        }
        
        cur = cur->next; // move pointers
    }
   
    printList(head); 
} // Time O(n), Space O(n)

// solution without extra memory
void dDups(Node *head){
    Node *cur = head;
    while(cur != nullptr){
        Node *runner = cur;
        while(runner->next != nullptr){
            if(runner->next->data == cur->data){
                runner->next = runner->next->next;
            } else{
                runner = runner->next;
            }
        }
        cur = cur->next;
    }
    // printList(head);
} // Time O(n^2), Space O(n);


int main(){
    Node *newList = nullptr; // creating list
    //adding to list
    vector<int> v = {5, 2, 3, 4, 2, 1, 6}; //the constructor adds them from right 
                                           //to left but it still works for this case


    for(auto a: v){
        newList = new Node(a, newList);
    }

    printList(newList);
    deleteDups(newList);
    // dDups(newList);

    return 0;
}

/*
    Before I move onto the solution without extra space
    I do want to point out a difference between my solution and the books solution

    The main difference is in the if statements, they check to see if its in the hash
    I check to see if its NOT in it, first

    Another one is our methods for traversal, they use the pointer given in the function,
    I use another seperate pointer to traverse

    Theirs definitely looks a lot cleaner but thats okay.
*/