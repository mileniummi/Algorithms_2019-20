#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <math.h>
using namespace std;

const int infinity = 1000000000;
struct Point {
    int x;
    int y;
};

int N;
vector<Point> peaks;

double get_dist(Point a, Point b) {
    return sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
}

double Prim_alg() {
    vector <double> min_dist(N, infinity);
    min_dist[0] = 0;
    vector<bool> used(N, false);
    double cost = 0;
    for (int i = 0; i < N; i++) {
        int v = -1;
        for (int j = 0; j < N; j++) {
            if ((!used[j]) && (v == -1 || min_dist[j] < min_dist[v])) {
                v = j;
            }
        }
        used[v] = true;
        cost += min_dist[v];
        double temp;
        for (int j = 0; j < N; j++) {
            if (j != v) {
                temp = get_dist(peaks[v], peaks[j]);
                if ((!used[j]) && (temp < min_dist[j])) {
                    min_dist[j] = temp;
                }
            }
        }
    }
    return cost;
}

int main() {
    ifstream fin;
    fin.open("spantree.in");
    ofstream fout;
    fout.open("spantree.out");
    int u;
    int v;
    fin >> N;
    peaks.resize(N);
    for (int i = 0; i < N; i++) {
        fin >> u >> v;
        peaks[i].x = u;
        peaks[i].y = v;
    }
    fout << setprecision(10) << Prim_alg();
    return 0;
}