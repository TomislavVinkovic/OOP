#pragma once

class Queue {
    unsigned int size, head, tail;
    int* container;

    public: 
        Queue(unsigned int);
        Queue(const Queue&);
        ~Queue();

        bool empty() const;
        bool full() const;

        void enqueue(int);
        int dequeue();

        void print() const;
};