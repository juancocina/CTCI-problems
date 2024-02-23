/**
 * @file 8.LoopDetection.cpp
 * @author Juan Cocina (juancocina1337@gmail.com)
 * @brief Given a linked list which might contain a loop, implement an algorithm that
 * returns the node at the beginning of the loop (if one exists).
 * @version 0.1
 * @date 2023-04-26
 * 
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

struct Node {
    char data;
    Node *next;
};

void append(Node* *h, char a){
    Node *p = *h;

    Node *n = new Node();
    n->data = a;
    n->next = nullptr;

    if(*h == nullptr){
        *h = n;
        return;
    }
    while(p->next != nullptr) p = p->next;

    p->next = n;
}

void prepend(Node* *h, char a){
    Node *n = new Node();
    n->data = a;
    n->next = nullptr;
    *h = n;
}

void print(Node* h){
    while(h != nullptr){
        cout << h->data << " ";
        h = h->next;
    }
    cout << endl;
}

/* sol start */
bool loopDetection(Node *l){
    unordered_set<Node*> n;
    while(l != nullptr){
        if(n.count(l)){
            cout << l->data << endl;
            return true;
        }
        else n.insert(l);
        l = l->next;
    }
    return false;
} // Time O(N), Space O(N)

// translating the books solution
bool loopD(Node* l){
    Node* f = l;
    Node* s = l;

    while(f != nullptr && f->next != nullptr){ //check if loop exist, move pointers first
        f = f->next->next;
        s = s->next;
        if(f == s) break;
    }
    if(f == nullptr || f->next == nullptr) return false; //if not loop return false

    s = l; // reset slow point
    while(s != nullptr && f != nullptr){
        if(s == f) {
            cout << s->data << endl;
            break;
        }
        s = s->next;
        f = f->next;
    }
    return true;
} // Time O(n), Space O(1)


/* sol end */
int main() {
    //create list
    vector<char> v1 = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    Node *l = nullptr;
    for(auto a: v1){
        append(&l, a);
    }

    print(l);

    //create loop
    Node *p1 = l;
    Node *p2 = nullptr;

    int c = 2;
    while(c != 0){ // locate c and point p2 to that location
        p1 = p1->next;
        c--;
    }
    p2 = p1;
    while(p1->next != nullptr) p1 = p1->next;
    p1->next = p2;

    //check for loop
    if(loopDetection(l)) cout << "Test 1: True\n";
    else cout << "Test 1: False\n";

    //make a new list using same chars, no loops...
    Node *p = nullptr;
    for(auto a: v1){
        append(&p, a);
    }
    if(loopDetection(p)) cout << "Test 2: True\n";
    else cout << "Test 2: False\n";

    //check for loop using books solution 
    if(loopD(l)) cout << "Test 1: True\n";
    else cout << "Test 1: False\n";

    if(loopD(p)) cout << "Test 2: True\n";
    else cout << "Test 2: False\n";

    return 0;
}

/*
    Alright heres the thing about this one, also a fairly easy question for me

    But I know theres two solutions
    The way I did it, using a set to store the nodes (their locations)
    and another way using two pointers

    The two pointer solution would result in O(1) space and the same time

    However, I don't really want to do that right now

    I'm sure for a HUGE HUGE list, it would definitely be a problem because it would take a lot of time
    especially if the Loop point is 1000 Nodes in, and the loop Node is Node number 3 in the list


*/