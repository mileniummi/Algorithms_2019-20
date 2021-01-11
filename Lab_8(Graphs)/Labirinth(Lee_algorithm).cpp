#include <iostream>
#include <fstream>
#include <vector>
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
    fin >> N >> M;
    vector <vector <char> >labirinth(N);
    vector<char> reverse_result;
    char symbol;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            fin >> symbol;
            labirinth[i].push_back(symbol);
        }
    }
    int start_i;
    int start_j;
    int finish_i;
    int finish_j;
    vector <vector<int>> Lee_labirinth(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (labirinth[i][j] == '#') {
                Lee_labirinth[i].push_back(-1);
            }
            else if (labirinth[i][j] == '.') {
                Lee_labirinth[i].push_back(-2);
            }
            else if (labirinth[i][j] == 'S') {
                start_i = i;
                start_j = j;
                Lee_labirinth[i].push_back(-2);
            }
            else if (labirinth[i][j] == 'T') {
                finish_i = i;
                finish_j = j;
                Lee_labirinth[i].push_back(-2);
            }

        }
    }
    ////////////////////////////LEEEEEEEEEEEEEE///////////
    bool stop;
    int di[4] = { 1, 0, -1, 0 };   // ????????, ??????????????? ??????? ??????
    int dj[4] = { 0, 1, 0, -1 };
    int d;
    d = 0;
    Lee_labirinth[start_i][start_j] = 0;
    do {
        stop = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (Lee_labirinth[i][j] == d) {
                    for (int k = 0; k < 4; ++k) {
                        int ii = i + di[k];
                        int jj = j + dj[k];
                        if (ii >= 0 && ii < N && jj >= 0 && jj < M &&
                            Lee_labirinth[ii][jj] == -2) {
                            stop = false;
                            Lee_labirinth[ii][jj] = d + 1;
                        }

                    }
                }
            }
        }
        d++;
    } while (!stop && Lee_labirinth[finish_i][finish_j] == -2);

    if (Lee_labirinth[finish_i][finish_j] == -2) {
        fout << -1;
        return 0;
    }
    int x = finish_i;
    int y = finish_j;
    while (d > 0) {
        d--;
        for (int k = 0; k < 4; k++) {
            int i = x + di[k];
            int j = y + dj[k];
            if (i >= 0 && i < N && j >= 0 && j < M &&
                Lee_labirinth[i][j] == d) {
                x = x + di[k];
                y = y + dj[k];
                if (di[k] == 1) {
                    reverse_result.push_back('U');
                    break;
                }
                if (di[k] == -1) {
                    reverse_result.push_back('D');
                    break;
                }
                if (dj[k] == 1) {
                    reverse_result.push_back('L');
                    break;
                }
                if (dj[k] == -1) {
                    reverse_result.push_back('R');
                    break;
                }
            }
        }
    }
    vector <char> result;
    for (int i = reverse_result.size() - 1; i >= 0; i--) {
        result.push_back(reverse_result[i]);
    }
    fout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++) {
        fout << result[i];
    }

}