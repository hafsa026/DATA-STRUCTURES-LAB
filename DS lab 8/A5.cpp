#include <iostream>
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
    if (T == NULL) {
        T = newNode(x);
        return T;
    }

    if (x > T->data) {
        // insert in right subtree
        T->right = insert(T->right, x);
        if (BF(T) == -2) {
            if (x > T->right->data)
                T = rotateLeft(T);                 // RR
            else {
                T->right = rotateRight(T->right);  // RL
                T = rotateLeft(T);
            }
        }
    } else if (x < T->data) {
        // insert in left subtree
        T->left = insert(T->left, x);
        if (BF(T) == 2) {
            if (x < T->left->data)
                T = rotateRight(T);                // LL
            else {
                T->left = rotateLeft(T->left);     // LR
                T = rotateRight(T);
            }
        }
    }
    T->ht = height(T);
    return T;
}

void preorder(node *r) {
    if (r) { cout << r->data << " "; preorder(r->left); preorder(r->right); }
}

void inorder(node *r) {
    if (r) { inorder(r->left); cout << r->data << " "; inorder(r->right); }
}

int main() {
    node *root = NULL;
    // This sequence forces LR, RL, LL, RR rotations
    int values[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    cout << "Preorder : "; preorder(root); cout << endl;
    cout << "Inorder  : "; inorder(root);  cout << endl;
    cout << "Height   : " << height(root) << endl;
    return 0;
}