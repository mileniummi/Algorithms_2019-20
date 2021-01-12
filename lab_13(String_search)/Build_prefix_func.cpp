#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> build_prefix(string t) {
    vector <int> pref(t.size() + 1);
    int i = 1, j = 0;
    while (i < t.size()) {
        if (t[i] == t[j]) {
            pref[i + 1] = j + 1;
            j++;
            i++;
        }
        else {
            if (j > 0) {
                j = pref[j];
            }
            else {
                pref[i + 1] = 0;
                i++;
            }
        }
    }
    return pref;
}


int main() {
    ifstream fin;
    fin.open("prefix.in");
    ofstream fout;
    fout.open("prefix.out");
    string t;
    fin >> t;
    vector<int> ans = build_prefix(t);
    for (size_t i = 1; i < ans.size(); i++)
    {
        fout << ans[i] << " ";
    }
    fin.close();
    fout.close();
    return 0;
}