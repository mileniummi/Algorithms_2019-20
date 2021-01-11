#include<iostream>
using namespace std;
int N;
struct Node {
public:
    int K;
    int L;
    int R;
};

int height(Node tree[], int i)
{
    int h1 = 0, h2 = 0;
    if (tree[i].L != 0) {
        h1 = height(tree, tree[i].L - 1);
        h1++;
    }
    if (tree[i].R != 0) {
        h2 = height(tree, tree[i].R - 1);
        h2++;
    }
    int ret = max(h1, h2);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("height.in", "r", stdin);
    freopen("height.out", "w", stdout);
    cin >> N;
    if (N == 0) {
        cout << 0;
        return 0;
    }
    Node tree[N];
    for (int i = 0; i < N; i++) {
        cin >> tree[i].K >> tree[i].L >> tree[i].R;
    }
    cout << height(tree, 0) + 1;
    return 0;
}