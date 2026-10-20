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

int leafCount = 0;

void printAndCountLeaves(bst *r) {
    if (r == NULL) return;
    if (r->left == NULL && r->right == NULL) {
        cout << r->id << " ";
        leafCount++;
        return;
    }
    printAndCountLeaves(r->left);
    printAndCountLeaves(r->right);
}

int main() {
    insert(8); insert(3); insert(10); insert(1);
    insert(6); insert(14); insert(4); insert(7); insert(13);

    cout << "Leaf nodes: ";
    printAndCountLeaves(root);
    cout << "\nTotal leaf nodes = " << leafCount << endl;
    return 0;
}