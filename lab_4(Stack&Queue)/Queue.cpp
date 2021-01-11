#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int x;
    Node* Next, * Prev;
};

class List
{
    Node* Head, * Tail;
public:
    List() :Head(NULL), Tail(NULL) {};
    void pop();
    void push(int x);
    int get_head();
};

void List::push(int x)
{
    Node* temp = new Node;
    temp->Next = NULL;
    temp->x = x;

    if (Head != NULL)
    {
        temp->Prev = Tail;
        Tail->Next = temp;
        Tail = temp;
    }
    else
    {
        temp->Prev = NULL;
        Head = Tail = temp;
    }
}
int  List::get_head()
{
    Node* temp = Head;
    return  temp->x;
}

void List::pop()
{
    Node* temp = Head;
    Head = Head->Next;
    delete temp;

}

int main() {
    ifstream fin;
    List queue;
    fin.open("queue.in");
    ofstream fout;
    fout.open("queue.out");
    int n;
    char a;
    int b;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> a;
        if (a == '+') {
            fin >> b;
            queue.push(b);
        }
        else if (a == '-') {
            fout << queue.get_head() << "\n";
            queue.pop();

        }
    }
}