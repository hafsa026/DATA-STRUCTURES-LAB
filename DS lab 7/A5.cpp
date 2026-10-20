#include <iostream>
using namespace std;

struct BST {
    int data;
    BST *left = NULL;
    BST *right = NULL;
};

BST *root = NULL;

void insert(int a) {
    BST *curr = new BST;
    curr->data = a;
    if (root == NULL) { root = curr; return; }
    BST *p = root, *q;
    while (p != NULL) {
        q = p;
        if (curr->data > q->data) p = p->right;
        else p = p->left;
    }
    if (curr->data > q->data) q->right = curr;
    else q->left = curr;
}

int count = 0;
int add = 0;

void sum(BST *s) {
    if (s != NULL) {
        count = count + 1;
        add = add + s->data;
        sum(s->left);
        sum(s->right);
    }
}

int main() {
    insert(8); insert(3); insert(10); insert(1);
    insert(6); insert(14); insert(4); insert(7); insert(13);

    sum(root);
    cout << "Total nodes = " << count << endl;
    cout << "Sum of nodes = " << add << endl;
    return 0;
}