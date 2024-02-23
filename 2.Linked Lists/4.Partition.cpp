/**
 * @file 4.Partition.cpp
 * @author Juan Cocina (juancocina1337@gmail.com)
 * @brief Partition: Write code to partition a linked list around a value x,
 *          such that all nodes less than x come before all nodes greater
 *          than or equal to x.
 * @version 0.1
 * @date 2023-04-01
 */

#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int data;
    Node *next;

    //constructor
    Node(int value, Node *n = nullptr){
        data = value;
        next = n;
    }
};

void printList(Node* head) {
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

void partition(Node *head, int p){
    if(head == nullptr || head->next == nullptr) return; // empty or one node
    
    Node *list1 = nullptr;
    Node *list2 = nullptr;

    while(head != nullptr) {
        if(head->data < p) list1 = new Node(head->data, list1);
        else list2 = new Node(head->data, list2);
        
        head = head->next;
    }
    Node *ptr = list1;
    while(ptr->next != nullptr) ptr = ptr->next;
    ptr->next = list2;

    printList(list1);
    
}  // Time O(N), Space O(N);

Node* pt(Node *head, int p) {
    Node *h = head;
    Node *t = head;

    while(head != nullptr) {
        Node *next = head->next;
        if(head->data < p){
            //insert node at head
            head->next = h;
            h = head;
        } else {
            t->next = head;
            t = head;
        }
        head = next;
    }
    t->next = nullptr;

    return h;
} // books solution

int main(){
    vector<int> v = {1, 2, 10, 5, 8, 5, 3};
    Node *newList = nullptr;
    for(auto a: v){
        newList = new Node(a, newList);
    }
    
    printList(newList);
    //partition(newList, 5);
    Node *n = pt(newList, 5);
    printList(n);
    return 0;
}

/*
    This one is a lliiiiittttle bit tricky, just because I'm not too sure about
    how they want the output to look like
    Do they need that space in between where the partition is?

    I managed to do the same thing that they did, maybe not at the fasted rate but it 
    works..
    But if they want that space I mean I can make that happened, I just wasn't sure

    After taking a look at the response I guess it doesn't really matter,
    it was just shown in the example to make sure the location
    of the partition was obvious.

    Another thing, the fact that I have a constructor in my struct makes it 
    easier to build a list. Wheras their solution requires a bit more work for that.

    I'm going to try to understand and translate their second solution.

    ...
    I think their solution is definitely faster and cleaner, thought it was a bit
    harder for me to understand.
*/