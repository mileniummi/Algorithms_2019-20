#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<int> used;

void dfs(int v, vector<int>& ans, vector <vector <int> >& adj_list) {
    used[v] = 1;
    for (size_t i = 0; i < adj_list[v].size(); ++i) {
        int to = adj_list[v][i];
        if (used[to] == 0)
            dfs(to, ans, adj_list);
    }
    used[v] = 2;
    ans.push_back(v);
}
void topological_sort(int N, vector<int>& ans, vector <vector <int> >& adj_list) {
    for (int i = 0; i < N; ++i)
        used.push_back(0);
    ans.clear();
    for (int i = 0; i < N; ++i)
        if (used[i] == 0)
            dfs(i, ans, adj_list);
    reverse(ans.begin(), ans.end());
}

int main() {
    ifstream fin;
    fin.open("hamiltonian.in");
    ofstream fout;
    fout.open("hamiltonian.out");
    int M;
    int N;
    int peak_1;
    int peak_2;
    fin >> N >> M;
    vector <vector <int> > adj_list(N, vector <int>());
    vector <int> ans(N);
    for (int i = 0; i < M; i++) {
        fin >> peak_1 >> peak_2;
        adj_list[peak_1 - 1].push_back(peak_2 - 1);
    }

    topological_sort(N, ans, adj_list);
    for (int i = 0; i < ans.size() - 1; i++) {
        int u = ans[i];
        int v = ans[i + 1];
        bool ispath = false;
        for (int j = 0; j < adj_list[u].size(); j++) {
            if (adj_list[u][j] == v) {
                ispath = true;
                break;
            }
        }
        if (ispath == false) {
            fout << "NO";
            return 0;
        }
    }
    fout << "YES";
