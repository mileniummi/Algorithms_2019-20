#include <iostream>
#include<fstream>
#include<iomanip>
using namespace std;

void main() {
    ifstream fin;
    fin.open("garland.in");
    int n;
    double A;
    fin >> n;
    fin >> A;
    double left = 0;
    double right = A;
    double last = -1;
    while ((right - left) > 0.01 / (n - 1))
    {
        double mid = (left + right) / 2;
        double prev = A;
        double current = mid;
        bool Above_ground = current > 0;
        for (int i = 3; i <= n; i++)
        {
            double next = 2 * current - prev + 2;
            prev = current;
            current = next;
            Above_ground &= next > 0;
        }
        if (Above_ground)
        {
            right = mid;
            last = current;
        }
        else
        {
            left = mid;
        }
    }
    ofstream fout;
    fout.open("garland.out");

    fout << fixed << setprecision(2) << last << endl;

}