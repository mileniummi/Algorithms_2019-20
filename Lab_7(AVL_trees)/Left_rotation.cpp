#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
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
class balanced_tree {
public:
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
    void tree_balancing();
    int get_balance(Node* v) {
        return get_height(v->r) - get_height(v->l);
    }
    Node* left_turn(Node* v) {
        Node* changed = v->r;
        v->r = changed->l;
        changed->l = v;
        changed->parent = v->parent;
        v->parent = changed;
        if (v->r != nullptr) {
            v->r->parent = v;
        }
        if (get_height(v->l) > get_height(v->r)) {
            v->height = get_height(v->l) + 1;
        }
        else {
            v->height = get_height(v->r) + 1;
        }
        if (get_height(changed->l) > get_height(changed->r)) {
            changed->height = get_height(changed->l) + 1;
        }
        else {
            changed->height = get_height(changed->r) + 1;
        }
        return changed;
    }
    Node* right_turn(Node* v) {
        Node* changed = v->l;
        v->l = changed->r;
        changed->r = v;
        changed->parent = v->parent;
        v->parent = changed;
        if (v->l != nullptr) {
            v->l->parent = v;
        }
        if (get_height(v->l) > get_height(v->r)) {
            v->height = get_height(v->l) + 1;
        }
        else {
            v->height = get_height(v->r) + 1;
        }
        if (get_height(changed->l) > get_height(changed->r)) {
            changed->height = get_height(changed->l) + 1;
        }
        else {
            changed->height = get_height(changed->r) + 1;
        }
        return changed;
    }

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
void balanced_tree::tree_balancing()
{
    if (get_balance(root->r) == -1) {
        root->r = right_turn(root->r);
        root->r->parent = root;
        root = left_turn(root);
    }
    else {
        root = left_turn(root);
    }

}


int main() {
    ifstream fin;
    fin.open("rotation.in");
    ofstream fout;
    fout.open("rotation.out");
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
    my_tree.tree_balancing();
    fout << N << "\n";
    queue<Node*> q;
    q.push(my_tree.root);
    int q_size = 1;
    int i = 0;
    Node* tmp;
    while (!q.empty()) {
        ++i;
        tmp = q.front();
        q.pop();
        --q_size;
        fout << tmp->k << ' ';
        if (tmp->l != nullptr) {
            q.push(tmp->l);
            fout << i + q_size + 1 << ' ';
            ++q_size;
        }
        else {
            fout << 0 << ' ';
        }
        if (tmp->r != nullptr) {
            fout << i + q_size + 1 << "\n";
            ++q_size;
            q.push(tmp->r);
        }
        else {
            fout << 0 << "\n";
        }
    }

}