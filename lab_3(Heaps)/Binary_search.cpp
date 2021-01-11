#include <iostream>
#include<fstream>
using namespace std;
int BinarySearchFirst(int A[], int key, int N)
{
    int left = 0, right = N, mid;
    while (right - left > 1)
    {

        mid = (left + right) / 2;
        if (key <= A[mid]) right = mid;
        else left = mid;

    }
    if (A[right - 1] == key)
        return right;
    if (A[right] == key) {
        return right + 1;
    }

    return -1;

}
int BinarySearchLast(int A[], int key, int N)
{
    int left = 0, right = N, mid;
    while (right - left > 1)
    {

        mid = (left + right) / 2;
        if (key < A[mid]) right = mid;
        else  left = mid;

    }
    if (A[right - 1] == key)
        return right;
    else {
        return -1;
    }

}
int main() {
    ifstream fin;
    fin.open("binsearch.in");
    int n;
    fin >> n;
    int* array = new int[n];
    for (int i = 0; i < n; i++) {
        fin >> array[i];
    }
    int m;
    fin >> m;
    ofstream fout;
    fout.open("binsearch.out");
    int* searching_numbers = new int[m];
    for (int i = 0; i < m; i++) {
        fin >> searching_numbers[i];
    }
    for (int i = 0; i < m; i++) {

        fout << BinarySearchFirst(array, searching_numbers[i], n) << " ";
        fout << BinarySearchLast(array, searching_numbers[i], n) << "\n";

    }
    delete[]array;
    return 0;
}