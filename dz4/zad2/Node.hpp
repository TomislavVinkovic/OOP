#pragma once

struct Node {
    Node* prev;
    Node* next;
    double value;

    Node();
    Node(double);
    Node(const Node&);

    //prilikom ciscenja, program mora ispisati adresu
    ~Node();

    //swap premjesta sadrzaj izmedu 2 cvora
    void swap(Node& n);
    void print() const;
};