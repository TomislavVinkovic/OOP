#include <iostream>
using namespace std;
using Data = int; // use Data as alias for int

class Node
{
public:
    Data _data;
    Node * _next;
    Node(Data data, Node* n):_data(data), _next(n){}
};
class List
{
protected:
    Node * head{};
public:
    List(){cout << "List()" << endl;}
    void push_front(Data);
    void display();
    Node * search(Data);
    bool erase(Data);
    ~List();
};
bool List::erase(Data d)
{
    Node * n = head;
    Node * previous_n;
    while (n != nullptr)
    {
        if (n->_data == d)
        {
            if (n == head) // first node contains the data d
            {
                head = n->_next; // adjust the head to point to the second node
                delete n;
                return true;
            }
            // some other node (not the first one) contains the data d
            previous_n->_next = n->_next; // bridge over node n
            delete n;
            return true;
        }
        previous_n = n;
        n = n->_next;
    }
    return false; // no data found!
}
Node* List::search(Data d)
{
    Node * n = head;
    while (n != nullptr)
    {
        if (n->_data == d)
            return n;
        n = n->_next;
    }
    return nullptr;
}
List::~List()
{
    cout << "~List()" << endl;
    Node * n = head;
    Node * for_delete;
    while(n != nullptr)
    {
        for_delete = n;
        n = n->_next;
        delete for_delete;
    }
}
void List::display()
{
    Node *n = head;
    while (n != nullptr)
    {
        cout << "| " << n->_data << " | " << n->_next << " | -- > " ;
        n = n->_next;
    }
    cout << " NULL " << endl;
}
void List::push_front(Data data)
{
    //Node n{data, head };
    Node *n = new Node{data, head};
    head = n;
}
int main()
{
    Data d1 = 1;
    Data d2 = 2;
    Data d3 = 3;
    Data d4 = 4;
    Data d5 = 5;
    List L{};
    L.push_front(d4);
    L.push_front(d3);
    L.push_front(d2);
    L.push_front(d1);

    L.display();
    cout << L.erase(d5) << endl;  // erase() returns false, d5 is not there
    L.display();
    cout << L.erase(d1) << endl; // erase() erases the appropriate node and returns true
    L.display();
    cout << L.erase(d3) << endl; // erase() erases the appropriate node and returns true
    L.display();

    cout << "search for d3 : " << L.search(d3) << endl;
    cout << "search for d4 : " << L.search(d4) << endl;

    return 0;
}
