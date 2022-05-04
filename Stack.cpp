#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    unsigned int size;
    int* container;
public:
    Stack(unsigned int);
    Stack(const Stack&);
    ~Stack();
    bool empty() const;
    bool full() const;
    void push(int);
    int pop();
    void print() const;
};

Stack::Stack(unsigned int n){
    top = -1;
    size = n;
    container = new int[n];
}

Stack::Stack(const Stack& s){
    top = s.top;
    size = s.size;
    container = new int[size];

    if(!s.empty())
        for(int i = 0; i<=s.top; i++)
            container[i] = s.container[i];

}

Stack::~Stack() {
    delete []container;
}

bool Stack::empty() const {
    return top == -1;
}

bool Stack::full() const {
    return top + 1 == size;
}

void Stack::push(int val) {
    if(!full()){
        top++;
        container[top] = val;
    }
}

int Stack::pop() {
    if(!empty()){
        int val = container[top];
        top--;
        return val;
    }
}

void Stack::print() const {
    cout << "Size: " << size << "\tTop: " << top << endl;
    if(!empty()){
        cout << "Container:\n";
        for(unsigned int i=0; i<=top; i++)
            cout << container[i] << "\t";
    }
    cout << "\n\n" << endl;
}

int main() {

    Stack s{10};

    int i=0;
    while(!s.full())
        s.push(++i);

    s.print();

    while(!s.empty())
        s.pop();

    s.print();

    while(!s.full())
        s.push(++i);

    while (15 != s.pop());

    Stack s1 = s;
    s.print();
    s1.print();

    while(!s.empty())
        s.pop();

    s.print();
    s1.print();

    for(int i = 1000; i < 2000; ++i)
        s.push(i);

    s.print();

    return 0;
}
