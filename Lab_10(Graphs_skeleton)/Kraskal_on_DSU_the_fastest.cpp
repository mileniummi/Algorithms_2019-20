#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> p;

int dsu_get(int v) {
    return (v == p[v]) ? v : (p[v] = dsu_get(p[v]));
}

void dsu_unite(int a, int b) {
    a = dsu_get(a);
    b = dsu_get(b);
    if (rand() & 1)
        swap(a, b);
    if (a != b)
        p[a] = b;
}

int N;
int M;
vector<pair <int, pair<int, int> > >graph;
long long cost = 0;
void kraskal() {
    sort(graph.begin(), graph.end());
    p.resize(N);
    for (int i = 0; i < N; i++) {
        p[i] = i;
    }
    int M = graph.size();
    for (int i = 0; i < M; i++) {
        int  a = graph[i].second.first, b = graph[i].second.second;
        int  l = graph[i].first;
        if (dsu_get(a) != dsu_get(b)) {
            cost += l;
            dsu_unite(a, b);
        }
    }
}
int main() {
    ifstream fin;
    fin.open("spantree3.in");
    ofstream fout;
    fout.open("spantree3.out");
    int u;
    int v;
    int dist;
    fin >> N >> M;
    graph.resize(M);
    for (int i = 0; i < M; i++) {
        fin >> u >> v >> dist;
        graph[i].first = dist;
        graph[i].second.first = u - 1;
        graph[i].second.second = v - 1;
    }
    kraskal();
    fout << cost;
    return 0;
}