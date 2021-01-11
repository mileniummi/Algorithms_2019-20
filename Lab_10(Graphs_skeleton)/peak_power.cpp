##include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin;
    fin.open("input.txt");
    ofstream fout;
    fout.open("output.txt");
    int M;
    int N;
    int u;
    int v;
    fin >> N >> M;
    vector <vector <int> > adj_list(N, vector <int>());
    vector <int> ans(N);
    for (int i = 0; i < M; i++) {
        fin >> u >> v;
        adj_list[u - 1].push_back(v - 1);
        adj_list[v - 1].push_back(u - 1);
    }
    for (int i = 0; i < N; i++) {
        fout << adj_list[i].size() << " ";
    }
    return 0;
}