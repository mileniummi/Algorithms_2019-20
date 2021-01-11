#include <iostream>
#include <fstream>
using namespace std;

void Heapify(int A[], int size, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && A[l] > A[largest])
        largest = l;

    if (r < size && A[r] > A[largest])
        largest = r;

    if (largest != i)
    {
        swap(A[i], A[largest]);
        Heapify(A, size, largest);
    }
}


void Heapsort(int A[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        Heapify(A, size, i);
    }
    for (int i = size - 1; i >= 0; i--)
    {
        swap(A[0], A[i]);
        Heapify(A, i, 0);
    }
}

int main() {
    ifstream fin;
    fin.open("sort.in");
    int n;
    fin >> n;
    int* array = new int[n];
    for (int i = 0; i < n; i++) {
        fin >> array[i];
    }

    Heapsort(array, n);

    ofstream fout;
    fout.open("sort.out");
    for (int i = 0; i < n; i++) {
        fout << array[i] << " ";
    }


}