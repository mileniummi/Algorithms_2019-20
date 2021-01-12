#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
long long MAXINT = 10000000000000;
int N, f, s;
vector<vector<long long>> graph;
vector<long long> dist;
vector<bool> used;

void Dijkstra() {
    used[s] = true;
    for (int i = 0; i < N; i++)
    {
        dist[i] = graph[s][i];
    }
    dist[s] = 0;
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
                if (dist[i] > dist[v] + graph[v][i]) {
                    dist[i] = dist[v] + graph[v][i];
                }
            }
        }

    }
}

int main() {
    ifstream fin;
    fin.open("pathmgep.in");
    ofstream fout;
    fout.open("pathmgep.out");
    fin >> N >> s >> f;
    f--;
    s--;
    graph.resize(N);
    dist.resize(N);
    used.resize(N);
    long long temp;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            fin >> temp;
            if (temp == -1) {
                temp = MAXINT;
            }
            graph[i].push_back(temp);
        }

    }
    Dijkstra();
    if (dist[f] == MAXINT)
        fout << -1;
    else
        fout << dist[f];

    fin.close();
    fout.close();
    return 0;
}