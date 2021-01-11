#include <iostream>
#include<fstream>
using namespace std;
void merge(int arr[], int left, int mid, int right) {
    int* temp_arr = new int[right - left + 1];
    int i = left;
    int j = mid + 1;
    int counter = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp_arr[counter] = arr[i];
            i++;
        }
        else {
            temp_arr[counter] = arr[j];
            j++;
        }
        counter++;
    }
    while (i <= mid) {
        temp_arr[counter] = arr[i];
        counter++;
        i++;
    }
    while (j <= right) {
        temp_arr[counter] = arr[j];
        counter++;
        j++;
    }
    for (i = left; i <= right; i++) {
        arr[i] = temp_arr[i - left];
    }
    delete[] temp_arr;
}
void sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        sort(arr, left, mid);
        sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main() {

    int n;
    ifstream fin;
    fin.open("sort.in");
    fin >> n;
    int* unsorted = new int[n];
    for (int i = 0; i < n; i++) {
        fin >> unsorted[i];
    }
    ofstream fout;
    fout.open("sort.out");
    sort(unsorted, 0, n - 1);
    for (int i = 0; i < n; i++) {
        fout << unsorted[i] << " ";
    }
    delete[] unsorted;
}
