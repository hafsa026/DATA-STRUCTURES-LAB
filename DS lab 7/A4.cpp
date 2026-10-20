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

// Returns number of comparisons; sets found flag
int search(int key, bool &found) {
    bst *p = root;
    int comparisons = 0;
    found = false;
    while (p != NULL) {
        comparisons++;
        if (key == p->id) { found = true; break; }
        else if (key < p->id) p = p->left;
        else p = p->right;
    }
    return comparisons;
}

int main() {
    insert(8); insert(3); insert(10); insert(1);
    insert(6); insert(14); insert(4); insert(7); insert(13);

    int key = 7;
    bool found;
    int c = search(key, found);
    if (found)
        cout << "Key " << key << " FOUND after " << c << " comparison(s)." << endl;
    else
        cout << "Key " << key << " NOT FOUND after " << c << " comparison(s)." << endl;

    key = 100;
    c = search(key, found);
    if (found)
        cout << "Key " << key << " FOUND after " << c << " comparison(s)." << endl;
    else
        cout << "Key " << key << " NOT FOUND after " << c << " comparison(s)." << endl;

    return 0;
}