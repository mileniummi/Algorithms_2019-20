#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int N;
    ifstream fin("smallsort.in");
    ofstream fout("smallsort.out");
    fin >> N;
    int* array = new int[N];
    for (int i = 0; i < N; ++i)
    {
        fin >> array[i];

    }
    for (int i = 1; i < N; i++) {
        int j = i - 1;
        while (j >= 0 && array[j] > array[j + 1]) {
            swap(array[j], array[j + 1]);
            j--;
        }
    }

    for (int i = 0; i < N; i++)
    {
        fout << array[i] << " ";
    }
    fin.close();
    fout.close();
}