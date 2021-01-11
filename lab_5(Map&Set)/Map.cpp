#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;
int hash_func(string str) {
    int p0 = 123456;
    int p = 1;
    int a = 0;
    for (int i = 0; i < str.size(); ++i) {
        a = abs((a + (int(str[i]) * p) % int(1e7)) % int(1e7));
        p = (p * p0) % int(1e7);
    }
    return a;
}
struct map
{
    string map_key;
    string map_value;
};

vector <vector <map> > Map(1e7 + 1, vector <map>());

int main()
{
    ios_base::sync_with_stdio(0);
    ifstream fin;
    fin.open("map.in");
    ofstream fout;
    fout.open("map.out");
    string operation;
    string key, value;
    while (fin >> operation) {
        fin >> key;
        int hash = hash_func(key);
        if (operation == "put") {
            fin >> value;
            bool ifEx = false;
            for (int i = 0; i < Map[hash].size(); ++i) {
                if (Map[hash][i].map_key == key) {
                    Map[hash][i].map_value = value;
                    ifEx = true;
                    break;
                }
            }
            if (!ifEx) {
                Map[hash].push_back({ key, value });
            }
        }
        else if (operation == "get") {
            bool ifEx = false;
            for (int i = 0; i < Map[hash].size(); ++i) {
                if (Map[hash][i].map_key == key) {
                    fout << Map[hash][i].map_value << endl;
                    ifEx = true;
                    break;
                }
            }
            if (!ifEx) {
                fout << "none" << endl;
            }
        }
        else {
            for (int i = 0; i < Map[hash].size(); ++i) {
                if (Map[hash][i].map_key == key) {
                    Map[hash][i].map_value = "none";
                    break;
                }
            }
        }
    }
    return 0;
}