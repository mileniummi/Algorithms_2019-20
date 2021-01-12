#include <iostream> 
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

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
void KMP(vector<int>& ans, string p, string t) {
    int n = p.size();
    string s = p + '#' + t;
    vector<int> pref = build_prefix(s);
    for (size_t i = 1; i < pref.size(); i++)
    {
        if (pref[i] == n) {
            ans.push_back(i - 2 * n - 1);
        }
    }
}

int main() {
    ifstream fin;
    fin.open("search2.in");
    ofstream fout;
    fout.open("search2.out");
    vector<int> ans;
    string p, t;
    fin >> p;
    fin >> t;
    KMP(ans, p, t);
    fout << ans.size() << endl;
    for (size_t i = 0; i < ans.size(); i++)
    {
        fout << ans[i] + 1 << " ";
    }
    fin.close();
    fout.close();
    return 0;
}