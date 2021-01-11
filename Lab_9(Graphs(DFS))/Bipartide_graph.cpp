#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector <char> color;

void dfs(int v, char c, vector <vector<int>>& adj_list, bool& bipartide) {
    color[v] = c;
    for (int i : adj_list[v]) {
        if (color[i] == 0) {
            dfs(i, c == 1 ? 2 : 1, adj_list, bipartide);
        }
        else if (color[i] == c) {
            bipartide = false;
            return;
        }
    }
}


int main() {
    ifstream fin;
    fin.open("bipartite.in");
    ofstream fout;
    fout.open("bipartite.out");
    int M;
    int N;
    int peak_1;
    int peak_2;
    fin >> N >> M;
    color.assign(N, 0);
    vector <vector <int> > adj_list(N, vector <int>());
    for (int i = 0; i < M; i++) {
        fin >> peak_1 >> peak_2;
        adj_list[peak_1 - 1].push_back(peak_2 - 1);
        adj_list[peak_2 - 1].push_back(peak_1 - 1);
    }
    bool bipartide = true;
    for (int i = 0; i < N; i++) {
        if (color[i] == 0) {
            dfs(i, 1, adj_list, bipartide);
        }
    }
    if (bipartide == true)
    {
        fout << "YES";
    }
    else
    {
        fout << "NO";
    }
    return 0;
}