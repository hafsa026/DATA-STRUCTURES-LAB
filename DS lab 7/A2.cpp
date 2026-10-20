#include <iostream>
using namespace std;

struct bst {
    int id;
    bst *left = NULL;
    bst *right = NULL;
};

bst *root = NULL;

void insert(int a) {
    bst *curr = new bst;
    curr->id = a;
    if (root == NULL) { root = curr; return; }
    bst *p = root, *q;
    while (p != NULL) {
        q = p;
        if (curr->id > q->id) p = p->right;
        else p = p->left;
    }
    if (curr->id > q->id) q->right = curr;
    else q->left = curr;
}

void preorder(bst *r) {
    if (r != NULL) {
        cout << r->id << " > ";
        preorder(r->left);
        preorder(r->right);
    }
}

void inorder(bst *r) {
    if (r != NULL) {
        inorder(r->left);
        cout << r->id << " > ";
        inorder(r->right);
    }
}

void postorder(bst *r) {
    if (r != NULL) {
        postorder(r->left);
        postorder(r->right);
        cout << r->id << " > ";
    }
}

int main() {
    insert(8); insert(3); insert(10); insert(1);
    insert(6); insert(14); insert(4); insert(7); insert(13);

    cout << "PreOrder : "; preorder(root); cout << endl;
    cout << "InOrder  : "; inorder(root);  cout << endl;
    cout << "PostOrder: "; postorder(root); cout << endl;
    return 0;
}