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

void inorder(bst *r) {
    if (r != NULL) {
        inorder(r->left);
        cout << r->id << " ";
        inorder(r->right);
    }
}

// Helper: find minimum node in a subtree
bst* minValueNode(bst* node) {
    bst* cur = node;
    while (cur && cur->left != NULL)
        cur = cur->left;
    return cur;
}

bst* deleteNode(bst* root, int key) {
    if (root == NULL) return root;

    if (key < root->id)
        root->left = deleteNode(root->left, key);
    else if (key > root->id)
        root->right = deleteNode(root->right, key);
    else {
        // Case 1 & 2: node with 0 or 1 child
        if (root->left == NULL) {
            bst* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            bst* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: node with 2 children
        bst* temp = minValueNode(root->right);
        root->id = temp->id;
        root->right = deleteNode(root->right, temp->id);
    }
    return root;
}

int main() {
    insert(50); insert(30); insert(70); insert(20);
    insert(40); insert(60); insert(80);

    cout << "Before deletion: "; inorder(root); cout << endl;

    cout << "\nDeleting leaf 20 (case 1)...\n";
    root = deleteNode(root, 20);
    inorder(root); cout << endl;

    cout << "\nDeleting node 30 with one child (case 2)...\n";
    root = deleteNode(root, 30);
    inorder(root); cout << endl;

    cout << "\nDeleting node 50 with two children (case 3)...\n";
    root = deleteNode(root, 50);
    inorder(root); cout << endl;

    return 0;
}