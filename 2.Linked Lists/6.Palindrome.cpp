/**
 * @file 6.Palindrome.cpp
 * @author Juan Cocina (juancocina1337@gmail.com)
 * @brief Implement a function to check if a linked list is a palindrome.
 * @version 0.1
 * @date 2023-04-22
 * 
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    char data;
    Node *next;
};

void append(Node* *h, char a){
    Node* p = *h;

    Node* n = new Node();
    n->data = a;
    n->next = nullptr;

    if(*h == nullptr){
        *h = n;
        return;
    }

    while(p->next != nullptr){
        p = p->next;
    }
    p->next = n;
}

void prepend(Node* *h, char a){
    Node *n = new Node();
    n->data = a;
    n->next = *h;
    *h = n;
}

void print(Node* h){
    while(h != nullptr){
        cout << h->data << " ";
        h = h->next;
    }
    cout << endl;
}

bool palindrome(Node *head){
    Node *sol = nullptr;
    Node *p = head;

    while(p != nullptr){
        prepend(&sol, p->data);
        p = p->next;
    }

    while(head != nullptr && sol != nullptr){
        if(head->data != sol->data)
            return false;

        head = head->next;
        sol = sol->next;
    }
    return true;
} // Time O(N), Space O(N)

int main() {
    vector<char> v1 = {'r', 'a', 'c', 'e', 'c', 'a', 'r'};
    vector<char> v2 = {'/', 'd', 'e', 'g', 'e', 'd', '/'};
    vector<char> v3 = {'s', 'e' , 'w', 'h', 'a', 'w', '5', '7', 's'};
    
    Node *list1 = nullptr;
    for(auto a: v1){
        append(&list1, a);
    }

    Node *list2 = nullptr;
    for(auto a: v2){
        append(&list2, a);
    }
    print(list1);   

    Node *list3 = nullptr;
    for(auto a: v3){
        append(&list3, a);
    }

    if(palindrome(list1)) cout << "Test 1: True" << endl;
    else cout << "Test 1: False" << endl;

    if(palindrome(list2)) cout << "Test 2: True" << endl;
    else cout << "Test 2: False" << endl;

    if(palindrome(list3)) cout << "Test 3: True" << endl;
    else cout << "Test 3: False" << endl;
    return 0;    
}

/*
    I was kind of sleepy while solving this one. I made a bunch of silly mistakes.

    Like creating append and prepened, when making a new node
    instead of typing new Node(), I just made it = nullptr;
    which is clearly not going to work..

    I got the solution after checking the first hint.
    Though I'm sure there are multiple ways to solve this, and probably better ways, 
    I am simply too tired to do that right now.

    I got to a solution by myself, and thats what im proud of.
*/