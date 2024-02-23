/**
 * @file 3.DeleteMiddleNode.cpp
 * @author Juan Cocina (juancocina1337@gmail.com)
 * @brief Delete Middle Node: Implement an algorithm to delete
 *        a node in the middle (i.e., any node but the first & last node,
 *        not necessarily the exact middle) of a singly linked list, given
 *        only access to that node.
 * @version 0.1
 * @date 2023-03-29
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    char data;
    Node *next;

    //constructor
    Node (char value, Node *n = nullptr) {
        data = value;
        next = n;
    }
};

void printList(Node *head){
    Node *ptr = head;
    while(ptr != nullptr){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
} // print list

void deleteMiddleNode(Node *n) {
    //zero or one node
    if(n->next == nullptr || n == nullptr) return; 
    
    Node *cur = n->next;
    n->data = cur->data;
    n->next = cur->next;
    
} //space O(1), time O(1)

int main() {
    vector<char> v = {'f', 'e', 'd', 'c', 'b', 'a'};
    Node *newList = nullptr;
    for(auto a : v){
        newList = new Node(a, newList);
    }
    printList(newList);

    //find and send the correct node 'c'
    Node *k = newList;
    while(k != nullptr){
        if(k->data == 'c') deleteMiddleNode(k);
        k = k->next;
    }
    printList(newList);

    return 0;
}

/*
    I got an idea for this one fairly quickly. 
    I wondered for a while how to do this one, and then I remembered you
    can modify data in the Nodes, and i started working from there.

    Truth be told, I'm in a rush to go to work, so I will admit,
    I did get stuck at some point
    I thought you have to continiously modify the data for each node
    from the point N and going forward
    so,
    a b c d e f
    c would become d, d would take e, e = f
    
    But I was left with an extra node at the end, which would have to be deleted.
    It makes so much sense to just change the pointer of the given node to
    next->next
    So the original d just basically gets skipped over.
    Pretty cool, kinda tricky, i wish I had more time to tackle this one
*/