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

// PreOrder with Right priority: Node -> Right -> Left  (NRL)
void preOrderNRL(bst *r) {
    if (r != NULL) {
        cout << r->id << " ";
        preOrderNRL(r->right);
        preOrderNRL(r->left);
    }
}

// InOrder with Right priority: Right -> Node -> Left  (RNL)
void inOrderRNL(bst *r) {
    if (r != NULL) {
        inOrderRNL(r->right);
        cout << r->id << " ";
        inOrderRNL(r->left);
    }
}

// PostOrder with Right priority: Right -> Left -> Node  (RLN)
void postOrderRLN(bst *r) {
    if (r != NULL) {
        postOrderRLN(r->right);
        postOrderRLN(r->left);
        cout << r->id << " ";
    }
}

int main() {
    insert(8); insert(3); insert(10); insert(1);
    insert(6); insert(14); insert(4); insert(7); insert(13);

    cout << "PreOrder (NRL): "; preOrderNRL(root);  cout << endl;
    cout << "InOrder  (RNL): "; inOrderRNL(root);   cout << endl;
    cout << "PostOrder(RLN): "; postOrderRLN(root);  cout << endl;
    return 0;
}