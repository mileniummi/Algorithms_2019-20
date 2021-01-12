#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
int n;
vector<vector<int>> ans;

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
void make_kmp(string s) {
    vector<int> pref = build_prefix(s);
    for (size_t q = 0; q < s.size() + 1; q++)
    {
        for (char a = 0; a < n; a++)
        {
            if (q > 0 && (a + 97) != s[q]) {
                ans[q][a] = ans[pref[q]][a];
            }
            else {
                ans[q][a] = q + ((a + 97) == s[q]);
            }
        }
    }
}

int main() {
    cin >> n;
    string s;
    cin >> s;
    ans.resize(s.size() + 1);
    for (size_t i = 0; i < ans.size(); i++) {
        ans[i].resize(n);
    }
    make_kmp(s);
    for (size_t i = 0; i < ans.size(); i++) {
        for (size_t j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}