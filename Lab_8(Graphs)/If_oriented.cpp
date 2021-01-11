#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin;
    fin.open("input.txt");
    ofstream fout;
    fout.open("output.txt");
    int M;
    int temp;
    fin >> M;
    int** sim_matrix = new int* [M];
    for (int i = 0; i < M; i++) {
        sim_matrix[i] = new int[M];
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            fin >> temp;
            sim_matrix[i][j] = temp;
        }
    }

    for (int i = 0; i < M; i++) {
        if (sim_matrix[i][i] == 1) {
            fout << "NO";
            return 0;
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if (sim_matrix[i][j] != sim_matrix[j][i]) {
                fout << "NO";
                return 0;
            }
        }
    }
    fout << "YES";
    for (int i = 0; i < M; i++) {
        delete[]sim_matrix[i];
    }
    delete[] sim_matrix;
    return 0;
}