#include <iostream>
#include <fstream>
#include <string>
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
    fin.open("postfix.in");
    ofstream fout;
    fout.open("postfix.out");
    char symbol;
    int b;
    int result;
    while (fin.get(symbol)) {
        if (symbol == ' ') {
        }
        else {
            if (((int)symbol > 47) && ((int)symbol < 58)) {
                while (true) {
                    if ((int)symbol == 48) { b = 0; break; }
                    if ((int)symbol == 49) { b = 1; break; }
                    if ((int)symbol == 50) { b = 2; break; }
                    if ((int)symbol == 51) { b = 3; break; }
                    if ((int)symbol == 52) { b = 4; break; }
                    if ((int)symbol == 53) { b = 5; break; }
                    if ((int)symbol == 54) { b = 6; break; }
                    if ((int)symbol == 55) { b = 7; break; }
                    if ((int)symbol == 56) { b = 8; break; }
                    if ((int)symbol == 57) { b = 9; break; }
                }
                stack.push(b);
            }
            else {
                if ((symbol) == '+') {
                    result = stack.pop() + stack.pop();
                    stack.push(result);
                }
                if ((symbol) == '-') {
                    int temp = stack.pop();
                    result = stack.pop() - temp;
                    stack.push(result);
                }
                if ((symbol) == '*') {
                    result = stack.pop() * stack.pop();
                    stack.push(result);
                }
            }
        }



    }
    fout << stack.pop();

}