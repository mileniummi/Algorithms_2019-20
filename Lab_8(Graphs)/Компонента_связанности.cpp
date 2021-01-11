#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;
void DFS(vector< vector<int> >& adj_list, vector <int>& components, int v, int N, int k) {
    components[v] = k;
    for (int i = 0; i < adj_list[v].size(); i++) {
        if (components[adj_list[v][i]] == -1) {
            DFS(adj_list, components, adj_list[v][i], N, k);
        }

    }
}

int main() {
    ifstream fin;
    fin.open("components.in");
    ofstream fout;
    fout.open("components.out");
    int M;
    int N;
    int peak_1;
    int peak_2;
    fin >> N >> M;
    vector <vector <int> > adj_list(N, vector <int>());
    vector <int> components(N, -1);
    for (int i = 0; i < M; i++) {
        fin >> peak_1 >> peak_2;
        adj_list[peak_1 - 1].push_back(peak_2 - 1);
        adj_list[peak_2 - 1].push_back(peak_1 - 1);
    }
    int edge = 0;
    int k = 1;
    for (int i = 0; i < N; i++) {
        if (components[i] == -1) {
            DFS(adj_list, components, i, N, k);
            k++;
        }
    }
    fout << k - 1 << "\n";
    for (int i = 0; i < components.size(); i++) {
        fout << components[i] << " ";
    }
}