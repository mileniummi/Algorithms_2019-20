#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<int> used;
vector <int> path;
vector <int> ans;
void dfs(int v, vector <vector <int> >& adj_list, bool& cycle) {
    used[v] = 1;
    for (size_t i = 0; i < adj_list[v].size(); ++i) {
        if (cycle) {
            return;
        }
        int to = adj_list[v][i];
        if (used[to] == 0) {
            path[to] = v;
            dfs(to, adj_list, cycle);
        }
        else if (used[to] == 1) {
            path[to] = to;
            int u = v;
            while (u != path[u]) {
                ans.push_back(u);
                u = path[u];
            }
            ans.push_back(u);
            cycle = true;
            return;
        }
    }
    if (cycle) {
        return;
    }
    used[v] = 2;
}

int main() {
    ifstream fin;
    fin.open("cycle.in");
    ofstream fout;
    fout.open("cycle.out");
    int M;
    int N;
    int peak_1;
    int peak_2;
    bool cycle = false;
    fin >> N >> M;
    used.assign(N, 0);
    path.assign(N, -1);
    vector <vector <int> > adj_list(N, vector <int>());
    for (int i = 0; i < M; i++) {
        fin >> peak_1 >> peak_2;
        adj_list[peak_1 - 1].push_back(peak_2 - 1);
    }
    for (int i = 0; i < N; ++i) {
        if (used[i] == 0 && cycle == false) {
            dfs(i, adj_list, cycle);
        };
    }
    if (cycle == false) {
        fout << "NO";
        return 0;
    }
    else {
        fout << "YES" << "\n";
        for (int i = ans.size() - 1; i >= 0; i--) {
            fout << ans[i] + 1 << " ";
        }
    }
}