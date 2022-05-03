#include "Node.hpp"
#include <iostream>

Node::Node(): prev{nullptr}, next{nullptr}, value{0} {}
Node::Node(double value): prev{nullptr}, next{nullptr}, value{value} {}

Node::Node(const Node& n) {
    next = n.next;
    prev = n.prev;
    value = n.value;
}

Node::~Node() {
    std::cout << "Delete node at: " << this << std::endl;
}

void Node::swap(Node& n) {
    double temp = value;
    value = n.value;
    n.value = temp;
}

void Node::print() const {
    std::cout << "Node at: " << this << "; " << "prev at: " 
              << prev << "; " << "next at: " << next << "; "
              << "value: " << value << std::endl;
}