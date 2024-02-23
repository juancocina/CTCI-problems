/**
 * @file 5.SumLists(forward).cpp
 * @author Juan Cocina (juancocina1337@gmail.com)
 * @brief 2.5 Sum Lists: You have two numbers represented by a linked list,
 * each node contains a single digit. The digits are stored in a reverse order, such that
 * the 1's digit is at the head of the list. Write a function that adds the two numbers & retrurns 
 * the sum as a linked list. (You are not allowed to "cheaet" & just conver the linked list to an integer).
 * 
 * @version 0.1
 * @date 2023-04-16
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void append(Node* *h, int d){
    Node *p = *h;
    //make a new node
    Node* n = new Node();
    n->data = d;
    n->next = nullptr;
    
    //if head is empty, make new node the head..
    if(*h == nullptr){
        *h = n;
        return;
    }
    //else traverse to the last node..
    while(p->next != nullptr) p = p->next;

    //change pointer to new last node
    p->next = n;
}

void print(Node *head){
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void prepend(Node* *h, int d){
    Node* n = new Node();
    n->data = d;
    n->next = *h;
    *h = n;
}

// solution
Node* sumLists(Node *a, Node *b){
    Node* sol = nullptr; // solution list that will be returned at the end
    int carry = 0;

    while(a != nullptr && b != nullptr){
        int c = carry;
        carry = 0;
        int p = 0, q = 0;
        // grab the data from the nodes
        if(a != nullptr) {
            p = a->data;
            a = a->next;
        }
        if(b != nullptr) {
            q = b->data;
            b = b->next;
        }
        // sum and append
        int s = p+q+c;
        carry = s / 10;
        append(&sol, s % 10);
    }
    if(a == nullptr && b == nullptr && carry != 0) 
        append(&sol, carry); // end of lists & carry exists
    else{ //if not at the end of lists...
        while(a != nullptr){ //if a is longer than b.. continue appending
            append(&sol, a->data+carry);
            carry = 0;
            a = a->next;
        }
        while(b != nullptr){ //if b is longer than a.. continue appending
            append(&sol, b->data+carry);
            carry = 0;
            b = b->next;
        }
    }
    return sol;
} // Time O(a+b), Space O(N)

// followup
Node* followUp(Node *a, Node *b){
    Node* solution = nullptr;
    int num1 = 0, num2 = 0;
    // add up the lists (*10 to generate the whole #)
    while(a != nullptr || b != nullptr){ 
        if(a != nullptr){
            num1 += a->data;
            if(a->next != nullptr)
                num1 *= 10;
            a = a->next;
        }
        if(b != nullptr){
           
            num2 += b->data;
            if(b->next != nullptr)
                num2 *= 10;
            b = b->next;
        }
    }
    int s = num1 + num2; // sum both the numbers
    
    // take the modulo of s, subract it from s, and divide s by 10 -> prepend to new list
    while(s != 0) {
        int m = s % 10;
        s -= m;
        s /= 10;
        prepend(&solution, m);
    }

    return solution;
} // Time O(a+b), Space O(N)

int main() {
    vector<int> v1 = {7, 1, 6};
    vector<int> v2 = {4, 5, 9, 3, 7};
    Node *list1 = nullptr;
    Node *list2 = nullptr;
    for(auto a: v1){
        append(&list1, a);
    }
    for(auto a: v2){
        append(&list2, a);
    }

    // follow up section
    vector<int> v3 = {9, 7, 8};
    vector<int> v4 = {6, 8, 5};
    Node *l1 = nullptr;
    Node *l2 = nullptr;
    for(auto a: v3) append(&l1, a);
    for(auto a: v4) append(&l2, a);
    
    print(sumLists(l1, l2));
    print(followUp(l1, l2));

    return 0;
}

/*
    This one was a bit difficult, simply because I didn't know how to get the
    append and prepend down. I had to use a book I had laying around to better understand those functions
    as well as some online resources.

    But I had the logic down fairly quickly from the jump, it was just those functions that took
    a lot of my time...

    I also had a bit of trouble with the follow up, unitl i understood how to add the number
    using *10, %10, and /10 to add/seperate the numbers...
*/