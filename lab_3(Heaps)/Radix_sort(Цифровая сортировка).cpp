
#include <iostream>
#include <fstream>
#include <string> 

using namespace std;
int ASCII(char a) {
    int b = a;
    return b;
}
char symbol = 'a';
string str[1000];
int count_mass[26];
void countSort(int n, int k)
{
    for (int i = 0; i < 26; i++)
    {
        count_mass[i] = 0;
    }
    string temp_str[1000];
    for (int i = 0; i < n; i++)
    {
        temp_str[i] = str[i];
    }
    for (int i = 0; i < n; i++)
    {
        count_mass[ASCII(temp_str[i][k]) - ASCII(symbol)]++;
    }
    for (int i = 1; i < 26; i++)
    {
        count_mass[i] += count_mass[i - 1];
    }
    for (int i = n - 1; i > -1; i--)
    {
        str[count_mass[ASCII(temp_str[i][k]) - ASCII(symbol)] - 1] = temp_str[i];
        count_mass[ASCII(temp_str[i][k]) - ASCII(symbol)]--;
    }
}

int main()
{
    ifstream fin("radixsort.in");
    ofstream fout("radixsort.out");
    long n, m, k;
    fin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        fin >> str[i];
    }

    for (int i = 0; i < k; i++)
    {
        countSort(n, m - i - 1);
    }

    for (int i = 0; i < n; i++)
    {
        fout << str[i] << "\n";
    }
    return 0;
}