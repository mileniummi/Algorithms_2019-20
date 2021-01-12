#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;


vector<vector<int>> graph_capacities;
vector<vector<int>> Fg;
vector<int> push;
vector<int> used;
vector<int> pred;
int max_flow;
int N, s, t;
int INF = 10000000;

void init()
{
    for (int i = 0; i < N; i++)
    {
        used[i] = 0;
        push[i] = 0;
        pred[i] = 0;
    }
}

int bfs(int s, int t)
{
    init();
    queue<int> Q;
    used[s] = 1;
    pred[s] = s;
    push[s] = INF;

    Q.push(s);
    while (!used[t] && !Q.empty())
    {
        int u = Q.front(); Q.pop();
        for (int v = 0; v < N; v++)
            if (!used[v] && (graph_capacities[u][v] - Fg[u][v] > 0))
            {
                push[v] = min(push[u], graph_capacities[u][v] - Fg[u][v]);
                used[v] = 1;
                pred[v] = u;
                Q.push(v);
            }
    }

    return used[t];
}

void Ford_Fulkerson()
{
    int u, v, flow = 0;

    while (bfs(s, t))
    {
        int add = push[t];

        v = t; u = pred[v];
        while (v != s)
        {
            Fg[u][v] += add;
            Fg[v][u] -= add;
            v = u; u = pred[v];
        }
        flow += add;
    }

    max_flow = flow;
}

int main()
{
    ifstream fin;
    fin.open("maxflow.in");
    ofstream fout;
    fout.open("maxflow.out");
    int M;
    fin >> N >> M;
    graph_capacities.resize(N);
    Fg.resize(N);
    push.resize(N);
    pred.resize(N);
    used.resize(N);
    s = 0;
    t = N - 1;
    for (size_t i = 0; i < N; i++)
    {
        graph_capacities[i].resize(N);
        Fg[i].resize(N);
    }
    int u, v, flow;
    for (size_t i = 0; i < M; i++)
    {
        fin >> u >> v >> flow;
        graph_capacities[u - 1][v - 1] = flow;
    }
    Ford_Fulkerson();

    fout << max_flow;
    fin.close();
    fout.close();
    return 0;
}