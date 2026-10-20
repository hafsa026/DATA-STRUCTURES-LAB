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

node* rotateLeft(node *x) {
    node *y = x->right;
    x->right = y->left;
    y->left = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}

// LR rotation: first left-rotate the left child, then right-rotate the node
node* LR(node *T) {
    T->left = rotateLeft(T->left);
    T = rotateRight(T);
    return T;
}

void preorder(node *r) {
    if (r) { cout << r->data << " "; preorder(r->left); preorder(r->right); }
}

int main() {
    // Classic LR case:
    //       30
    //      /
    //     10
    //       \
    //        20
    node *root = newNode(30);
    root->left = newNode(10);
    root->left->right = newNode(20);

    root->left->right->ht = 0;
    root->left->ht        = height(root->left);
    root->ht              = height(root);

    cout << "Before LR rotation (preorder): "; preorder(root); cout << endl;

    root = LR(root);

    cout << "After LR rotation (preorder): "; preorder(root); cout << endl;
    return 0;
}