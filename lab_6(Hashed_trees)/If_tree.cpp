#include<iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<int> Tree;
int N;

struct Node {
public:
    int K;
    int L;
    int R;
};


void go(Node node[], int x)
{
    if (node[x].L != NULL) {
        go(node, node[x].L - 1);
    }
    Tree.push_back(node[x].K);
    if (node[x].R != NULL) {
        go(node, node[x].R - 1);
    }
}


int main() {
    ifstream fin;
    ofstream fout;
    fin.open("check.in");
    fout.open("check.out");
    fin >> N;
    if (N == 0) {
        fout << "YES";
        return 0;
    }
    Node tree[N];
    for (int i = 0; i < N; i++) {
        fin >> tree[i].K >> tree[i].L >> tree[i].R;
    }
    go(tree, 0);
    bool iftree = true;
    for (int i = 0; i < Tree.size() - 1; i++) {
        if (Tree[i] >= Tree[i + 1]) {
            iftree = false;
            break;
        }
    }
    iftree == true ? fout << "YES" : fout << "NO";
}