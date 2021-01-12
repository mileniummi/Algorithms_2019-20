#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream fin;
    fin.open("search1.in");
    ofstream fout;
    fout.open("search1.out");
    vector<int> ans;
    string p, t;
    fin >> p;
    fin >> t;
    int n = t.size();
    int m = p.size();
    if (n < m) {
        fout << 0;
        return 0;
    }
    bool match = true;

    for (size_t i = 0; i < n - m + 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (p[j] != t[j + i]) {
                match = false;
                break;
            }
        }
        if (match == true) {
            ans.push_back(i + 1);
        }
        match = true;
    }
    fout << ans.size() << endl;
    for (size_t i = 0; i < ans.size(); i++)
    {
        fout << ans[i] << " ";
    }

    fin.close();
    fout.close();
    return 0;
}