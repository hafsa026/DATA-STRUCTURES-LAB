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

node* insert(node *T, int x) {
    if (T == NULL) return newNode(x);

    if (x > T->data) {
        T->right = insert(T->right, x);
        if (BF(T) == -2) {
            if (x > T->right->data) T = rotateLeft(T);
            else { T->right = rotateRight(T->right); T = rotateLeft(T); }
        }
    } else if (x < T->data) {
        T->left = insert(T->left, x);
        if (BF(T) == 2) {
            if (x < T->left->data) T = rotateRight(T);
            else { T->left = rotateLeft(T->left); T = rotateRight(T); }
        }
    }
    T->ht = height(T);
    return T;
}

node* minNode(node *T) {
    node *cur = T;
    while (cur && cur->left != NULL) cur = cur->left;
    return cur;
}

node* Delete(node *T, int x) {
    if (T == NULL) return NULL;

    if (x > T->data) {
        // delete from right subtree
        T->right = Delete(T->right, x);
        if (BF(T) == 2) {
            if (BF(T->left) >= 0)
                T = rotateRight(T);            // LL
            else {
                T->left = rotateLeft(T->left); // LR
                T = rotateRight(T);
            }
        }
    } else if (x < T->data) {
        // delete from left subtree
        T->left = Delete(T->left, x);
        if (BF(T) == -2) {
            if (BF(T->right) <= 0)
                T = rotateLeft(T);             // RR
            else {
                T->right = rotateRight(T->right); // RL
                T = rotateLeft(T);
            }
        }
    } else {
        // found the node
        if (T->right != NULL) {
            // replace with in-order successor
            node *p = minNode(T->right);
            T->data = p->data;
            T->right = Delete(T->right, p->data);
            if (BF(T) == 2) {
                if (BF(T->left) >= 0)
                    T = rotateRight(T);
                else {
                    T->left = rotateLeft(T->left);
                    T = rotateRight(T);
                }
            }
        } else {
            // no right child ? return left child
            return T->left;
        }
    }
    T->ht = height(T);
    return T;
}

void preorder(node *r) {
    if (r) { cout << r->data << " "; preorder(r->left); preorder(r->right); }
}

void inorder(node *r) {
    if (r) { inorder(r->left); cout << r->data << " "; inorder(r->right); }
}

int main() {
    node *root = NULL;
    int vals[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
    int n = sizeof(vals) / sizeof(vals[0]);
    for (int i = 0; i < n; i++) root = insert(root, vals[i]);

    cout << "Initial preorder : "; preorder(root); cout << endl;

    cout << "\nDeleting 10 (leaf)...\n";
    root = Delete(root, 10);
    cout << "Preorder after delete 10 : "; preorder(root); cout << endl;

    cout << "\nDeleting 70 (with one child 80)...\n";
    root = Delete(root, 70);
    cout << "Preorder after delete 70 : "; preorder(root); cout << endl;

    cout << "\nDeleting 30 (with two children)...\n";
    root = Delete(root, 30);
    cout << "Preorder after delete 30 : "; preorder(root); cout << endl;

    cout << "Inorder  after delete 30 : "; inorder(root); cout << endl;
    return 0;
}