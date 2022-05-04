#include <iostream>

using namespace std;

class Queue {
protected:
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

Queue::Queue(unsigned int size): size{size+1}, head{0}, tail{0}, container{new int[size+1]}{}

Queue::Queue(const Queue& q): size{q.size}, head{q.head}, tail{q.tail}, container{new int[q.size]}{
    if(!q.empty())
        for(unsigned int i=head; i!=tail;i=(i+1)%size)
            container[i] =q.container[i];
}

Queue::~Queue() {
    delete[] container;
}

bool Queue::empty() const {
    return head == tail;
}

bool Queue::full() const {
    return head == (tail+1)%size;
}

void Queue::print() const {
    if(!empty())
        for(unsigned int i=head; i!=tail;i=(i+1)%size)
            cout << container[i] << "\t";

        cout << "\n\n";
}

void Queue::enqueue(int value) {
    if(!full()){
        container[tail++] = value;
        tail = tail%size;
    }
}

int Queue::dequeue(){
       int to_return = container[head++];
        head = head%size;
        return to_return;
}

int main() {

    Queue q{10};

    int arr[]={1,2,3,4,5,6,7,8,9,10};

    for(auto el: arr){
        q.enqueue(el);
        q.print();
    }
    cout << "\n\n";

    for(auto el : arr){
        if(!q.empty()){
            q.enqueue(q.dequeue()+1);
            q.print();
        }
    }

    cout << "\n\n";

    while(!q.empty()){
        cout << q.dequeue()<< ": ";
        q.print();
    }


    return 0;
}
