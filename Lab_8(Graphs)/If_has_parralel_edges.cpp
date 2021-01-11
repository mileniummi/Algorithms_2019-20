#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin;
    fin.open("input.txt");
    ofstream fout;
    fout.open("output.txt");
    int M;
    int N;
    int peak_1;
    int peak_2;
    fin >> M >> N;
    int** sim_matrix = new int* [M];
    for (int i = 0; i < M; i++) {
        sim_matrix[i] = new int[M];
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            sim_matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        fin >> peak_1 >> peak_2;
        if (sim_matrix[peak_1 - 1][peak_2 - 1] == 1) {
            fout << "YES";
            return 0;
        }
        if (sim_matrix[peak_2 - 1][peak_1 - 1] == 1) {
            fout << "YES";
            return 0;
        }
        sim_matrix[peak_1 - 1][peak_2 - 1] = 1;
    }
    fout << "NO";
    for (int i = 0; i < M; i++) {
        delete[]sim_matrix[i];
    }
    delete[] sim_matrix;
    return 0;
}