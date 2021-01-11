#include<iostream>
#include<fstream>
#include <vector>
#include <list>
#include<string>
#include<cmath>

int const m = 1000001;
using namespace std;

int hash_func(int k)
{
    return abs(k % 1000001);
}


int main() {

    list<int>* array = new list<int>[m];
    string operation;
    int temp;
    string ifEx = "false";
    ifstream fin;
    fin.open("set.in");
    ofstream fout;
    fout.open("set.out");
    while (!fin.eof()) {
        operation = "";
        fin >> operation;
        if (operation == "insert") {
            fin >> temp;
            array[hash_func(temp)].push_back(temp);
        }
        if (operation == "delete") {
            fin >> temp;
            array[hash_func(temp)].remove(temp);

        }
        if (operation == "exists") {
            fin >> temp;
            for (auto i = array[hash_func(temp)].begin(); i != array[hash_func(temp)].end(); i++) {
                if (*i == temp) {
                    ifEx = "true";
                    break;
                }
            }
            fout << ifEx << "\n";
            ifEx = "false";
        }

    }
    delete[]array;
}