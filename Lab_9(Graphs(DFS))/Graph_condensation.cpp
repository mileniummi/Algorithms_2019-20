#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector <bool> used;
vector <int> ord;
vector <int> component;

void dfs1(int v, vector <vector<int>>& adj_list) {
    used[v] = true;
    for (int i = 0; i < adj_list[v].size(); i++) {
        if (!used[adj_list[v][i]]) {
            dfs1(adj_list[v][i], adj_list);
        }
    }
    ord.push_back(v);
}
void dfs2(int v, vector <vector<int>>& reverse_adj_list, int& comp) {
    used[v] = true;
    component[v] = comp;
    for (int i = 0; i < reverse_adj_list[v].size(); i++) {
        if (!used[reverse_adj_list[v][i]]) {
            dfs2(reverse_adj_list[v][i], reverse_adj_list, comp);
        }
    }
}

int main() {
    ifstream fin;
    fin.open("cond.in");
    ofstream fout;
    fout.open("cond.out");
    int M;
    int N;
    int peak_1;
    int peak_2;
    fin >> N >> M;
    vector <vector <int> > adj_list(N, vector <int>());
    vector <vector <int> > reverse_adj_list(N, vector <int>());
    for (int i = 0; i < M; i++) {
        fin >> peak_1 >> peak_2;
        adj_list[peak_1 - 1].push_back(peak_2 - 1);
        reverse_adj_list[peak_2 - 1].push_back(peak_1 - 1);
    }
    component.assign(N, 0);
    used.assign(N, false);
    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            dfs1(i, adj_list);
        }
    }
    used.assign(N, false);
    int comp = 1;
    for (int i = ord.size() - 1; i >= 0; i--) {
        if (component[ord[i]] == 0) {
            dfs2(ord[i], reverse_adj_list, comp);
            comp++;
        }
    }
    fout << comp - 1 << "\n";
    for (int i = 0; i < component.size(); i++) {
        fout << component[i] << " ";
    }
    return 0;
}