#pragma once

struct Node {
    int value{};
    Node* next{};

    Node();
    ~Node();
    Node(int, Node*);
    Node(const Node&);

};