#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;
long long INF = 1e18 * 2;
int N, M, S;
struct Edge {
    Edge(int v_, long long cost_) {
        v = v_;
        cost = cost_;
    }
    int v;
    long long cost;
};
vector<vector<Edge>> graph;
vector<long long> dist;
vector <int> negative(N);

void dfs(int v) {
    negative[v] = 2;
    for (int i = 0; i < graph[v].size(); i++) {
        if (negative[graph[v][i].v] != 2) {
            dfs(graph[v][i].v);
        }
    }
}


void Floyd(int v) {
    dist[v] = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < graph[j].size(); k++) {
                if (dist[j] < INF) {
                    if (dist[graph[j][k].v] > dist[j] + graph[j][k].cost) {
                        dist[graph[j][k].v] = max(dist[j] + graph[j][k].cost, -INF);
                    }
                }
            }
        }
    }
}
int main() {
    ifstream fin;
    fin.open("path.in");
    ofstream fout;
    fout.open("path.out");
    fin >> N >> M >> S;
    S--;
    graph.resize(N);
    dist.resize(N, INF);
    negative.resize(N);
    int u, v;
    long long cost;
    for (int i = 0; i < M; i++) {
        fin >> u >> v >> cost;
        graph[u - 1].push_back(Edge(v - 1, cost));

    }
    Floyd(S);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            if (dist[i] < INF) {
                if (dist[i] < INF) {
                    if (negative[graph[i][j].v] == 0 && (dist[graph[i][j].v] > dist[i] + graph[i][j].cost)) {
                        negative[graph[i][j].v] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (negative[i] == 1) {
            dfs(i);
        }
    }
    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] == INF) {
            fout << "*" << "\n";
        }
        else if (negative[i] == 2) {
            fout << "-" << "\n";
        }
        else {
            fout << dist[i] << "\n";
        }
    }
    fin.close();
    fout.close();
    return 0;
}