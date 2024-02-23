/**
 * @file 7.Intersection.cpp
 * @author Juan Cocina (juancocina1337@gmail.com)
 * @brief Given two (singly) linked lists, determine if the two lits intersect. Return the intersecting node.
 * Note that the intersection is defined based on reference, not value.
 * That is, if the kth node of the first linked list is the exact same node (by reference)
 * as the jth node of the second linked list, then they are intersecting.
 * @version 0.1
 * @date 2023-04-26
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node *next;
};

void append(Node* *h, int c){
    Node *p = *h;
    
    Node *n = new Node();
    n->data = c;
    n->next = nullptr;

    //if the list is empty
    if(*h == nullptr){
        *h = n;
        return;
    }

    while(p->next != nullptr) p = p->next;

    p->next = n;
}

void prepend(Node* *h, int c){
    Node *n = new Node();
    n->data = c;
    n->next = nullptr;
    *h = n;
}

void print(Node *h){
    while(h != nullptr){
        cout << h->data << " ";
        h = h->next;
    }
    cout << endl;
}

bool checkInteresection(Node* *a, Node* *b){
    if(*a == *b) {
        cout << "Node A: " << (*a)->data << "... Node B: " << (*b)->data << endl;
        cout << "Node A location: " << *a << "... Node B location: " << *b << endl;
        return true;
    }
    return false;
}

int checkLength(Node *l){
    int c = 0;
    while(l != nullptr){
        l = l->next;
        c++;
    }
    return c;
}

bool interesection(Node *list1, Node *list2){
    if(list1 == nullptr || list2 == nullptr) return false;

    // which list is the longer one?
    int c = 0;
    if(checkLength(list1) > checkLength(list2)){
        c = checkLength(list1) - checkLength(list2);
        while(c != 0){ //if list1 is longer... move it along until lengths are equal
            list1 = list1->next;
            c--;
        }
    }
    else{
        c = checkLength(list2) - checkLength(list1);
        while(c != 0){ //move it along until lengths are equal
            list2 = list2->next;
            c--;
        }
    }

    while(list1 != nullptr || list2 != nullptr){
        if(list1 != nullptr && list2 != nullptr){
            if(checkInteresection(&list1, &list2)) return true;
            else {
                list1 = list1->next;
                list2 = list2->next;
            }
        }
    }

    return false;
} // Time O(l1 + l2), Space O(1)

int main() {
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> v2 = {3, 2, 1};

    vector<int> v3 = {6, 7, 8};
    vector<int> v4 = {1, 2, 3, 4, 5, 3, 2, 1};

    Node *l1 = nullptr;
    for(auto a: v1){
        append(&l1, a);
    }
    Node *l2 = nullptr;
    for(auto a: v2){
        append(&l2, a);
    }

    Node *l3 = nullptr;
    for(auto a: v3){
        append(&l3, a);
    }
    Node *l4 = nullptr;
    for(auto a: v4){
        append(&l4, a);
    }

    /* creating intersection*/
    // print(l1);
    // print(l2);

    Node *p1 = l1;
    Node *p2 = l2;
    //creating intersection for lists 1 and 2
    int c = 5;
    while(c != 0){
        p1 = p1->next;
        c--;
    }
    while(p2->next != nullptr){
        p2 = p2->next;
    }
    p2->next = p1;
    //creating intersection for lists 3 and 4
    p1 = l3;
    p2 = l4;
    c = 2;
    while(c != 0){
        p2 = p2->next;
        c--;
    }
    while(p1->next != nullptr){
        p1 = p1->next;
    }
    p1->next = p2;

    /* intersection creation print */
    print(l1);
    print(l2);

    /* call for interesection check */
    if(interesection(l1, l2)) cout << "Test 1: True\n" << endl;
    else cout << "Test 1: False\n" << endl;

    /* intersection creation print */
    print(l3);
    print(l4);

    /* call for interesection check */
    if(interesection(l3, l4)) cout << "Test 2: True\n" << endl;
    else cout << "Test 2: False\n" << endl;


    //two different lists with the same nodes
    vector<int> n = {1,2,3,4};
    vector<int> m = {1,2,3,4};
    Node *ln = nullptr;
    for(auto a: n){
        append(&ln, a);
    }
    Node *lm = nullptr;
    for(auto a: m){
        append(&lm, a);
    }
    
    print(ln);
    print(lm);
    if(interesection(ln, lm)) cout << "Test 3: True\n" << endl;
    else cout << "Test 3: False\n" << endl;

    return 0;
}

/*
    The thing about this problem is that in order to test it, I need to find a way to 
    intersect two lists

    What I could do is make a list, lets say 8 nodes long
    and make a second list, 3 nodes long, and intersect on the 4th node

    I mentally understood the solution 

    ....
       ****Changing the value of C on line 97 will produce different intersections
    My first example is making two lists
    Using C = 3;
    List 1 = {1, 2, 3, 4, 5, 6, 7, 8};
    List 2 = {3, 2, 1};

    Inside of main, I make it so that List2's last node points to List1s 4th node

    ....
    By changing the value of C from 3 to 4 the lists become
    List 1 = {1, 2, 3, 4, 5, 6, 7, 8};
    List 2 = {3, 2, 1, 5, 6, 7, 8};
    The intersection is now at node 5,
    The current way that my algorithm works is that both lists move at the same rate, so
    the nodes won't be checked correctly

    What adjustment do I make to correct this?
    I could count the lengths of each list and then move the pointers
    using the difference of each length

    ============

    Alright this problem was pretty easy up front
    I didn't really want to have to count the lists but it is what it is.
*/
