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

void preorder(node *r) {
    if (r) { cout << r->data << " "; preorder(r->left); preorder(r->right); }
}

int main() {
    // Unbalanced:
    //      30
    //     /
    //    20
    //   /
    //  10
    node *root = newNode(30);
    root->left = newNode(20);
    root->left->left = newNode(10);

    root->left->left->ht = 0;
    root->left->ht       = height(root->left);
    root->ht             = height(root);

    cout << "Before rotation (preorder): "; preorder(root); cout << endl;

    root = rotateRight(root);

    cout << "After right rotation (preorder): "; preorder(root); cout << endl;
    return 0;
}