#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;
void BFS(vector< vector<int> >& adj_list, vector<int>& peaks_distance, int v) {
    list<int> queue;
    queue.push_back(v);
    while (!queue.empty()) {
        v = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj_list[v].size(); i++) {
            if (peaks_distance[adj_list[v][i]] == -1) {
                peaks_distance[adj_list[v][i]] = peaks_distance[v] + 1;
                queue.push_back(adj_list[v][i]);
            }
        }
    }
}

int main() {
    ifstream fin;
    fin.open("pathbge1.in");
    ofstream fout;
    fout.open("pathbge1.out");
    int M;
    int N;
    int peak_1;
    int peak_2;
    fin >> N >> M;
    vector <vector <int> > adj_list(N, vector <int>());
    vector <int> peaks_distance(N, -1);
    for (int i = 0; i < M; i++) {
        fin >> peak_1 >> peak_2;
        adj_list[peak_1 - 1].push_back(peak_2 - 1);
        adj_list[peak_2 - 1].push_back(peak_1 - 1);
    }
    peaks_distance[0] = 0;
    BFS(adj_list, peaks_distance, 0);
    for (int i = 0; i < peaks_distance.size(); i++) {
        fout << peaks_distance[i] << " ";
    }
}