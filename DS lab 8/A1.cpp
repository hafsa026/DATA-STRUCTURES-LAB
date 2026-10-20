#include <iostream>
using namespace std;

struct node {
    int data;
    node *left = NULL;
    node *right = NULL;
    int ht = 0;   // height of this node
};

int height(node *T) {
    int lh, rh;
    if (T == NULL) return 0;
    if (T->left == NULL) lh = 0;
    else lh = 1 + T->left->ht;
    if (T->right == NULL) rh = 0;
    else rh = 1 + T->right->ht;
    if (lh > rh) return lh;
    return rh;
}

// helper to build a node
node* newNode(int x) {
    node *n = new node;
    n->data = x;
    n->ht = 0;
    return n;
}

int main() {
    // Build a small tree manually:
    //        10
    //       /  \
    //      5    20
    //     /
    //    2
    node *root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(20);
    root->left->left = newNode(2);

    // update heights bottom-up
    root->left->left->ht = height(root->left->left);
    root->left->ht        = height(root->left);
    root->right->ht       = height(root->right);
    root->ht              = height(root);

    cout << "Height of tree = " << root->ht << endl;
    return 0;
}