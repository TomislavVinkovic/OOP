#pragma once

struct Node {
    double value{};
    Node* next{};

    Node();
    Node(double);
    Node(const Node&);
    ~Node();
    void print() const;

};