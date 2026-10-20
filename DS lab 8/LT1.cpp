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

// LL case
node* LL(node *T) { return rotateRight(T); }
// RR case
node* RR(node *T) { return rotateLeft(T); }
// LR case
node* LR(node *T) {
    T->left = rotateLeft(T->left);
    return rotateRight(T);
}
// RL case
node* RL(node *T) {
    T->right = rotateRight(T->right);
    return rotateLeft(T);
}

void preorder(node *r) {
    if (r) { cout << r->data << " "; preorder(r->left); preorder(r->right); }
}

int main() {
    // ---- LL case ----
    node *a = newNode(30);
    a->left = newNode(20);
    a->left->left = newNode(10);
    a->left->left->ht = 0;
    a->left->ht       = height(a->left);
    a->ht             = height(a);
    cout << "LL before: "; preorder(a); cout << endl;
    a = LL(a);
    cout << "LL after : "; preorder(a); cout << endl << endl;

    // ---- RR case ----
    node *b = newNode(10);
    b->right = newNode(20);
    b->right->right = newNode(30);
    b->right->right->ht = 0;
    b->right->ht        = height(b->right);
    b->ht               = height(b);
    cout << "RR before: "; preorder(b); cout << endl;
    b = RR(b);
    cout << "RR after : "; preorder(b); cout << endl << endl;

    // ---- LR case ----
    node *c = newNode(30);
    c->left = newNode(10);
    c->left->right = newNode(20);
    c->left->right->ht = 0;
    c->left->ht        = height(c->left);
    c->ht              = height(c);
    cout << "LR before: "; preorder(c); cout << endl;
    c = LR(c);
    cout << "LR after : "; preorder(c); cout << endl << endl;

    // ---- RL case ----
    node *d = newNode(10);
    d->right = newNode(30);
    d->right->left = newNode(20);
    d->right->left->ht = 0;
    d->right->ht       = height(d->right);
    d->ht              = height(d);
    cout << "RL before: "; preorder(d); cout << endl;
    d = RL(d);
    cout << "RL after : "; preorder(d); cout << endl;

    return 0;
}