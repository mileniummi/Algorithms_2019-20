#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;
long long INF = 1e9;
int N;
struct Edge {
    int u, v;
    long long cost;
};
vector<Edge> graph;
vector<long long> dist;
vector <int> p;

long long Negative_Cycle() {
    dist.resize(N);
    long long v;
    for (int i = 0; i < N; i++) {
        v = -1;
        for (int j = 0; j < graph.size(); j++) {
            if (dist[graph[j].u] < INF) {
                if (dist[graph[j].v] > dist[graph[j].u] + graph[j].cost) {
                    dist[graph[j].v] = max(-INF, dist[graph[j].u] + graph[j].cost);
                    p[graph[j].v] = graph[j].u;
                    v = graph[j].v;
                }
            }
        }

    }
    return v;
}

int main() {
    ifstream fin;
    fin.open("negcycle.in");
    ofstream fout;
    fout.open("negcycle.out");
    fin >> N;
    graph.resize(N);
    p.resize(N, -1);
    long long cost;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fin >> cost;
            if (cost != int(1e9)) {
                graph.push_back({ i, j, cost });
            }
        }
    }
    long long x = Negative_Cycle();
    if (x == -1) {
        fout << "NO";
    }
    else {
        for (int i = 0; i < N; i++) {
            x = p[x];
        }
        vector<long long> ans;
        for (long long i = x; ; i = p[i])
        {
            ans.push_back(i);
            if (i == x && ans.size() > 1) break;
        }
        reverse(ans.begin(), ans.end());
        fout << "YES" << "\n";
        fout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++)
        {
            fout << ans[i] + 1 << " ";
        }
    }

    fin.close();
    fout.close();
    return 0;
}