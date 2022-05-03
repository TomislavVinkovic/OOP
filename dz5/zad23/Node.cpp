#include "Node.hpp"
#include <iostream>

using namespace std;

Node::Node() {}

Node::~Node() {
    cout << "Node deleted at: " << this << endl;
}

Node::Node(int value, Node* n): value{value}, next{n} {}

Node::Node(const Node& n) {
    value = n.value;
    next = n.next;
}