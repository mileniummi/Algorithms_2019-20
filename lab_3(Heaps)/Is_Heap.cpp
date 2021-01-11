#include <iostream>
#include<fstream>
using namespace std;
int Ifheap(int array[], int N)
{
    bool ifheap = true;
    for (int i = 0; ((2 * i) + 1) < N; i++) {

        if (!(array[i] < array[(2 * i) + 1])) {
            ifheap = false;
        }
    }
    for (int i = 0; ((2 * i) + 2) < N; i++) {
        if (!(array[i] < array[(2 * i) + 2]))
            ifheap = false;
    }
    if (ifheap == true)
        return 1;
    else return 0;

    return -1;


}

int main() {
    ifstream fin;
    fin.open("isheap.in");
    int n;
    fin >> n;
    int* array = new int[n];

    for (int i = 0; i < n; i++) {
        fin >> array[i];
    }
    ofstream fout;
    fout.open("isheap.out");
    if (Ifheap(array, n) == 1)
        fout << "YES";
    else
        fout << "NO";
}