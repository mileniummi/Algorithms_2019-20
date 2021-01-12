#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


vector<vector<int>> first_half;
vector<vector<int>> second_half;
vector<int> used;

bool dfs(int v)
{
    if (used[v])
    {
        return false;
    }
    used[v] = true;
    for (int i = 0; i < first_half[v].size(); i++)
    {
        if (second_half[first_half[v][i]].empty())
        {
            second_half[first_half[v][i]].push_back(v);
            return true;
        }
        if (dfs(second_half[first_half[v][i]][0]))
        {
            second_half[first_half[v][i]].pop_back();
            second_half[first_half[v][i]].push_back(v);
            return true;
        }
    }
    return false;
}


void init() {
    for (size_t i = 0; i < used.size(); i++)
    {
        used[i] = 0;
    }
}


int main()
{
    ifstream fin;
    fin.open("matching.in");
    ofstream fout;
    fout.open("matching.out");
    int N, M, K;
    fin >> N >> M >> K;
    first_half.resize(N);
    second_half.resize(M);
    used.resize(N);
    int u, v;
    for (size_t i = 0; i < K; i++)
    {
        fin >> u >> v;
        first_half[u - 1].push_back(v - 1);

    }
    for (size_t i = 0; i < N; i++)
    {
        dfs(i);
        init();
    }
    int max_matching = 0;
    for (size_t i = 0; i < M; i++)
    {
        max_matching += second_half[i].size();
    }
    fout << max_matching;
    fin.close();
    fout.close();

}