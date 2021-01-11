#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<bool> used;
vector <vector <int> > adj_list;
vector<int> marks;
vector <int> topsort;

void mark_dfs(int v) {
    used[v] = true;
    if (adj_list[v].empty()) {
        marks[v] = 2;//����������� 
    }
    else {
        for (size_t i = 0; i < adj_list[v].size(); ++i) {
            int to = adj_list[v][i];
            if (used[to] == false)
                mark_dfs(to);
        }
    }
    int count = 0;
    for (size_t i = 0; i < adj_list[v].size(); ++i) {
        if (marks[adj_list[v][i]] == 2) {
            marks[v] = 1;
            break;
        }
        if (marks[adj_list[v][i]] == 1) {
            count++;
        }
    }
    if (count == adj_list[v].size()) {
        marks[v] = 2;
    }
    used[v] = true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ifstream fin("game.in");
    ofstream fout("game.out");
    int N;
    int M;
    int S;
    int u;
    int v;
    fin >> N >> M >> S;
    S -= 1;
    adj_list.resize(N);
    used.resize(N, false);
    marks.resize(N, 0);

    for (int i = 0; i < M; i++) {
        fin >> u >> v;
        adj_list[u - 1].push_back(v - 1);
    }
    mark_dfs(S);
    if (marks[S] == 1) {
        fout << "First player wins";
    }
    else if (marks[S] == 2) {
        fout << "Second player wins";
    }
};