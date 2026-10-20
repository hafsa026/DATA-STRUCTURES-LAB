#include <iostream>
using namespace std;

struct BST {
    int data;
    BST *left = NULL;
    BST *right = NULL;
};

BST *root = NULL;

BST* recursiveInsert(BST *r, int val) {
    if (r == NULL) {
        BST *n = new BST;
        n->data = val;
        return n;
    }
    if (val < r->data)
        r->left = recursiveInsert(r->left, val);
    else if (val > r->data)
        r->right = recursiveInsert(r->right, val);
    // if equal, ignore duplicate
    return r;
}

void inorder(BST *r) {
    if (r != NULL) {
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }
}

int main() {
    root = recursiveInsert(root, 50);
    root = recursiveInsert(root, 30);
    root = recursiveInsert(root, 70);
    root = recursiveInsert(root, 20);
    root = recursiveInsert(root, 40);
    root = recursiveInsert(root, 60);
    root = recursiveInsert(root, 80);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    return 0;
}