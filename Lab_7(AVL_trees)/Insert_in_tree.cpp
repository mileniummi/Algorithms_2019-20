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
    Node* el = new Node;
    balanced_tree(int n) {
        root = nullptr;
        tree.resize(n, *el);
    }
    void insert(int i, int k, int l, int r);
    unsigned int get_height(Node* v) {
        return v ? v->height : 0;
    }
    void find_root();
    void fix_height(Node* temp);
    void find_height();
    void tree_balancing();
    void add(int x);
    int get_balance(Node* v) {
        return get_height(v->r) - get_height(v->l);
    }
    Node* left_turn(Node* v);
    Node* right_turn(Node* v);
    Node* big_left_turn(Node* node);
    Node* big_right_turn(Node* node);
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
void balanced_tree::fix_height(Node* node)
{
    if (get_height(node->l) > get_height(node->r)) {
        node->height = get_height(node->l) + 1;
    }
    else {
        node->height = get_height(node->r) + 1;
    }
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
void balanced_tree::add(int x) {
    if (root == nullptr) {
        root = new Node;
        root->k = x;
        return;
    }
    Node* temp = root;
    Node* prev = nullptr;
    while (temp != nullptr) {
        prev = temp;
        if (x > temp->k) {
            temp = temp->r;
        }
        else if (x < temp->k) {
            temp = temp->l;
        }
        else {
            return;
        }
    }
    Node* new_el = new Node;
    new_el->k = x;
    new_el->parent = prev;
    if (new_el->parent->k > new_el->k) {
        new_el->parent->l = new_el;
    }
    else {
        new_el->parent->r = new_el;
    }
    temp = prev;
    while (temp != nullptr) {
        fix_height(temp);
        if (get_balance(temp) == 2) {
            if (get_balance(temp->r) == -1) {
                temp = big_left_turn(temp);
            }
            else {
                temp = left_turn(temp);
            }
        }

        if (get_balance(temp) == -2) {
            if (get_balance(temp->l) == 1) {
                temp = big_right_turn(temp);
            }
            else {
                temp = right_turn(temp);
            }
        }
        if (temp->parent != nullptr) {
            if (temp->parent->k > temp->k) {
                temp->parent->l = temp;
            }
            else {
                temp->parent->r = temp;
            }
        }
        else {
            root = temp;
        }
        temp = temp->parent;
    }
}
Node* balanced_tree::left_turn(Node* v)
{
    Node* changed = v->r;
    v->r = changed->l;
    changed->l = v;
    changed->parent = v->parent;
    v->parent = changed;
    if (v->r != nullptr) {
        v->r->parent = v;
    }
    fix_height(v);
    fix_height(changed);
    return changed;
}
Node* balanced_tree::right_turn(Node* v)
{
    Node* changed = v->l;
    v->l = changed->r;
    changed->r = v;
    changed->parent = v->parent;
    v->parent = changed;
    if (v->l != nullptr) {
        v->l->parent = v;
    }
    fix_height(v);
    fix_height(changed);
    return changed;
}
Node* balanced_tree::big_left_turn(Node* node)
{
    node->r = right_turn(node->r);
    node->r->parent = node;
    node = left_turn(node);
    return node;
}
Node* balanced_tree::big_right_turn(Node* node) {
    node->l = left_turn(node->l);
    node->l->parent = node;
    node = right_turn(node);
    return node;
}
int main() {
    ifstream fin;
    fin.open("addition.in");
    ofstream fout;
    fout.open("addition.out");
    int key;
    int N;
    int K;
    int L;
    int R;
    fin >> N;
    balanced_tree my_tree(N);
    vector<int> nodes(N);
    for (int i = 0; i < N; i++) {
        fin >> K >> L >> R;
        nodes[i] = K;
        my_tree.insert(i, K, L - 1, R - 1);
    }
    fin >> key;
    my_tree.find_root();
    my_tree.find_height();
    my_tree.add(key);
    fout << N + 1 << "\n";
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