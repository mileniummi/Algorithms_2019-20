#include <iostream>
#include <fstream>
using namespace std;
struct Node
{
    int value;
    Node* Next;
};

class List
{

public:
    Node* Top;
    List() : Top(NULL) {};
    int pop();
    void push(int x);
};

void List::push(int x)
{
    Node* temp = new Node;
    temp->value = x;
    temp->Next = Top;
    Top = temp;
}

int List::pop()
{

    Node* temp = Top;
    temp = Top;
    Top = Top->Next;
    return temp->value;

}

int main() {
    ifstream fin;
    List stack;
    fin.open("stack.in");
    ofstream fout;
    fout.open("stack.out");
    int n;
    char a;
    int b;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> a;
        if (a == '+') {
            fin >> b;
            stack.push(b);
        }
        else if (a == '-') {
            fout << stack.pop() << "\n";
        }
    }
}