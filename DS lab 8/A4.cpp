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

int main() {
    //       30
    //      /  \
    //    10    40
    //      \
    //      20
    node *root = newNode(30);
    root->left = newNode(10);
    root->right = newNode(40);
    root->left->right = newNode(20);

    root->left->right->ht = 0;
    root->left->ht        = height(root->left);
    root->right->ht       = height(root->right);
    root->ht              = height(root);

    cout << "Balance factor of root(30) = " << BF(root) << endl;
    cout << "Balance factor of node(10) = " << BF(root->left) << endl;
    cout << "Balance factor of node(40) = " << BF(root->right) << endl;
    return 0;
}