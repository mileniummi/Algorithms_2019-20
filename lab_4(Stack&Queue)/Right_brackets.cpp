#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node
{
    char value;
    Node* Next;
};

class List
{

public:
    Node* Top;
    List() : Top(NULL) {};
    char pop();
    void push(char x);
};

void List::push(char x)
{
    Node* temp = new Node;
    temp->value = x;
    temp->Next = Top;
    Top = temp;
}

char List::pop()
{
    if (Top == NULL) {
        return -1;
    }
    Node* temp = Top;
    temp = Top;
    Top = Top->Next;
    return temp->value;

}

int main() {
    ifstream fin;
    List stack;
    fin.open("brackets.in");
    ofstream fout;
    fout.open("brackets.out");
    string str;
    char k;
    bool bracket = true;
    while (getline(fin, str)) {

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(' or str[i] == '[')
            {
                stack.push(str[i]);
            }
            if (str[i] == ')' or str[i] == ']')
            {
                k = stack.pop();
                if (str[i] == ')' and k != '(' or k == -1 or str[i] == ']' and k != '[')
                {
                    bracket = false;
                    break;
                }
            }
        }

        if (bracket and stack.Top == NULL)
        {
            fout << "YES\n";
        }
        else
        {
            fout << "NO\n";
        }
        stack.Top = NULL;
        bracket = true;
    }
    fin.close();
    fout.close();


}