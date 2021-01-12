#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
long long INF = 10000000000000;
int N;
int M;
vector<vector<long long>> adj_matrix;
vector<vector<long long>> distance_;

void Dijkstra(int s, vector<long long>& dist) {
    vector<bool> used(N);
    used[s] = true;

    for (int i = 0; i < N; i++)
    {
        if (i != s) {
            int v = -1;
            for (int j = 0; j < N; j++)
            {
                if (!used[j] && (v == -1 || dist[j] < dist[v]))
                    v = j;
            }
            used[v] = true;
            for (int i = 0; i < N; i++) {
                if (dist[i] > dist[v] + adj_matrix[v][i]) {
                    dist[i] = dist[v] + adj_matrix[v][i];
                }
            }
        }

    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    ifstream fin;
    fin.open("pathsg.in");
    ofstream fout;
    fout.open("pathsg.out");
    int  u, v, cost;
    fin >> N >> M;
    adj_matrix.resize(N, vector<long long>(N, INF));
    for (size_t i = 0; i < M; i++)
    {
        fin >> u >> v >> cost;
        adj_matrix[u - 1][v - 1] = cost;
    }

    distance_ = adj_matrix;

    for (size_t i = 0; i < N; i++)
    {
        Dijkstra(i, distance_[i]);
    }

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            if (i == j)
                fout << 0 << " ";
            else
                fout << distance_[i][j] << " ";
        }
        fout << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}