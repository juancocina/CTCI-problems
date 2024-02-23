/*
    4.1 Route Between Nodes:
    Given a directed graph and two nodes (S and E), design
    an algorithm to find out whether there is a route from S to E.

    So we have a directed graph and two nodes.
    We are checking if there is a route between the two, so we return boolean

    The difficulty for me here is that I would have a rough idea of what I want to do,
    but not too much experience with directed graphs.

    So there might be three solutions here
    1) DFS
    2) BFS
    3) Bidirectional search

    Each would tell me if there is a route between the two nodes
    Lets just start with DFS and BFS,

    What are the pros and cons with each?
    Both algorithms will definitely tell me if the route exists
    DFS might be a little easier to implement than DFS
*/

#include<string>
#include<unordered_set>
#include<vector>
#include<iostream>

class Node {
    public:
        std::string name;
        std::vector<Node*> children;

        Node(std::string n) {
            this->name = n;
        }
};

class Graph {
    public:
        std::vector<Node*> nodes;
};

std::unordered_set<std::string> visited; // assuming all nodes are unique

void dfs(Node* root) {
    if(root = nullptr) return;

    //insert into unordered_set
    visited.insert(root->name);
    for(auto n: root->children) {
        if(n != nullptr && !visited.count(n->name))
            dfs(n);
    }
    return;
}

bool routeBetweenNodes(Node* start, Node* end) {
    if(start == nullptr || end == nullptr) return false;
    if(start == end) return true;

    dfs(start);
    if(visited.count(end->name)) return true;
    return false;
}

void route(Node* start, Node* end) {
    std::cout << start->name;
}

int main() {
    Node* a = new Node("A");
    Node* b = new Node("B");
    Node* c = new Node("C");
    Node* d = new Node("D");
    Node* e = new Node("E");
    Node* f = new Node("F");
    Node* s = new Node("S");

    s->children.push_back(a);
    a->children.push_back(b);
    b->children.push_back(c);
    b->children.push_back(s);
    c->children.push_back(b);

    e->children.push_back(f);
    f->children.push_back(d);
    d->children.push_back(e);

    Graph gr;
    gr.nodes = {s, a, b, c, d, e, f};


    for(auto firstLayer : gr.nodes) {
        if(firstLayer != nullptr) {
            std::cout << firstLayer->name << ": ";
            for(auto secondLayer : firstLayer->children) {
                if(secondLayer == nullptr) break;
                std::cout << secondLayer->name << ", ";
            }
        }
        std::cout << std::endl;
    }

    if(routeBetweenNodes(s, e)) std::cout << "True" << std::endl;
    else std::cout << "False" << std::endl;

    return 0;
}