#include <iostream>
#include <queue>
using namespace std;

struct node {
    int data;
    node *left = NULL;
    node *right = NULL;
    int ht = 0;
};

int height(node *T) {
    int lh, rh;
    if (T == NULL) return 0;
    if (T->left == NULL) lh = 0;
    else lh = 1 + T->left->ht;
    if (T->right == NULL) rh = 0;
    else rh = 1 + T->right->ht;
    return (lh > rh) ? lh : rh;
}

int BF(node *T) {
    int lh, rh;
    if (T == NULL) return 0;
    if (T->left == NULL) lh = 0;
    else lh = 1 + T->left->ht;
    if (T->right == NULL) rh = 0;
    else rh = 1 + T->right->ht;
    return (lh - rh);
}

node* newNode(int x) {
    node *n = new node;
    n->data = x;
    n->ht = 0;
    return n;
}

node* rotateRight(node *x) {
    node *y = x->left;
    x->left = y->right;
    y->right = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}

node* rotateLeft(node *x) {
    node *y = x->right;
    x->right = y->left;
    y->left = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}

node* insert(node *T, int x) {
    if (T == NULL) return newNode(x);

    if (x > T->data) {
        T->right = insert(T->right, x);
        if (BF(T) == -2) {
            if (x > T->right->data) T = rotateLeft(T);
            else { T->right = rotateRight(T->right); T = rotateLeft(T); }
        }
    } else if (x < T->data) {
        T->left = insert(T->left, x);
        if (BF(T) == 2) {
            if (x < T->left->data) T = rotateRight(T);
            else { T->left = rotateLeft(T->left); T = rotateRight(T); }
        }
    }
    T->ht = height(T);
    return T;
}

// Level-order (BFS) traversal
void levelOrder(node *root) {
    if (root == NULL) return;
    queue<node*> q;
    q.push(root);
    int level = 0;

    while (!q.empty()) {
        int sz = q.size();
        cout << "Level " << level << ": ";
        for (int i = 0; i < sz; i++) {
            node *cur = q.front(); q.pop();
            cout << cur->data << " ";
            if (cur->left)  q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        cout << endl;
        level++;
    }
}

int main() {
    node *root = NULL;
    int vals[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
    int n = sizeof(vals) / sizeof(vals[0]);
    for (int i = 0; i < n; i++) root = insert(root, vals[i]);

    cout << "Level-order traversal of AVL tree:\n";
    levelOrder(root);
    return 0;
}