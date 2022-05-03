#include "Node.hpp"
#include <iostream>

Node::Node() {}

Node::Node(double value): value{value} {}

Node::Node(const Node& n) {
    value = n.value;
    next = n.next;
}

Node::~Node() {}

void Node::print() const {
    std::cout << value << std::endl;
}