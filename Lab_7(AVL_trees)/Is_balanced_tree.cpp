#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
class balanced_tree {
public:
    struct Node {
        int k;
        Node* l;
        Node* r;
        Node* parent;
        int height;
        Node() {
            this->k = -1;
            this->l = nullptr;
            this->r = nullptr;
            this->parent = nullptr;
            this->height = 1;
        }
    };
    Node* root;
    vector<Node> tree;
    map<int, int> balance;
    balanced_tree(int n) {
        root = nullptr;
        tree.resize(n);
    }
    void insert(int i, int k, int l, int r);
    unsigned int get_height(Node* v) {
        return v ? v->height : 0;
    }
    void find_root();
    void find_height();
};

void balanced_tree::insert(int i, int k, int l, int r)
{
    tree[i].k = k;
    if (l != -1) {
        tree[i].l = &tree[l];
        tree[l].parent = &tree[i];
    }
    if (r != -1) {
        tree[i].r = &tree[r];
        tree[r].parent = &tree[i];
    }
    return;
}

void balanced_tree::find_root()
{
    for (int i = 0; i < tree.size(); i++) {
        if (tree[i].parent == nullptr) {
            root = &tree[i];
            break;
        }
    }
    return;
}
void balanced_tree::find_height()
{
    queue <Node*> q;
    for (int i = 0; i < tree.size(); ++i) {
        if (tree[i].l == nullptr && tree[i].r == nullptr) {
            q.push(&tree[i]);
        }
    }
    Node* v;
    int l_height, r_height;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        l_height = get_height(v->l);
        r_height = get_height(v->r);
        balance[v->k] = r_height - l_height;
        if (v->parent != nullptr) {
            v->parent->height = max(v->height + 1, v->parent->height);
            q.push(v->parent);
        }
    }
    return;
}


int main() {
    ifstream fin;
    fin.open("balance.in");
    ofstream fout;
    fout.open("balance.out");
    int N;
    int K;
    int L;
    int R;
    fin >> N;
    if (N == 0) {
        fout << 0;
        return 0;
    }
    balanced_tree my_tree(N);
    vector<int> nodes(N);
    for (int i = 0; i < N; i++) {
        fin >> K >> L >> R;
        nodes[i] = K;
        my_tree.insert(i, K, L - 1, R - 1);
    }
    my_tree.find_root();
    my_tree.find_height();
    for (int i = 0; i < N; i++) {
        fout << my_tree.balance[nodes[i]] << "\n";
    }