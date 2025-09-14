
#include <bits/stdc++.h>
using namespace std;

// Compact, well-commented BST implementation with: insert, search, delete,
// inorder/preorder/postorder, level-order, simple pretty-print and a concise main.

struct Node {
    int key;
    Node* left;
    Node* right;
    explicit Node(int k) : key(k), left(nullptr), right(nullptr) {}

};

Node* findMin(Node* root) {
    while (root && root-> left) root = root->left;
    return root;

}

Node* insertNode(Node* root, int k) {
    if (!root) return new Node(k);
    if (k < root-> key) root-> left = insertNode(root->left, k);
    // duplicates ignored
    return root;
}

Node* searchIterative(Node* root, int k) {
    while (root) {
        if (k == root->key) return root;
        root  = (k < root->key) ? root-> left : root->right;
    }
    return nullptr;
}

Node* deleteNode(Node* root, int k) {
    if (!root) return nullptr;
    if (k < root->key) root->left = deleteNode(root->left, k);
    else if (k > root->key) root->right = deleteNode(root->right, k);
    else {
        if (!root->left) {
            Node* r = root->right; delete root; return r;
        }
        if (!root->right) {
            Node* l = root->left; delete root; return l;
        }
        Node* succ = findMin(root->right);
        root->key = succ->key;
        root->right = deleteNode(root->right, succ->key);
    }
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << ' ';
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->key << ' ';
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << ' ';
}

void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q; q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            Node* cur = q.front(); q.pop();
            cout << cur->key << ' ';
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        cout << '\n';
    }
}

// Simple sideways print for small trees
void printTree(Node* root, string pref = "", bool isLeft = true) {
    if (!root) return;
    if (root->right) printTree(root->right, pref + (isLeft ? "│ " : " "), false);
    cout << pref << (isLeft ? "└──" : "┌──") << root->key << '\n';
    if (root->left) printTree(root->left, pref + (isLeft ? " " : "│ "), true);
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    Node* root = nullptr;
    vector<int> vals = {50, 30, 70, 20, 40, 60, 80};
    for (int v : vals) root = insertNode(root, v);


    cout << "BST:\n"; printTree(root); cout << '\n';


    cout << "Inorder: "; inorder(root); cout << "\n";
    cout << "Preorder: "; preorder(root); cout << "\n";
    cout << "Postorder: "; postorder(root); cout << "\n\n";


    cout << "Level-order:\n"; levelOrder(root); cout << '\n';


    cout << "Search 40: " << (searchIterative(root, 40) ? "Found\n" : "Not Found\n");
    cout << "Search 25: " << (searchIterative(root, 25) ? "Found\n" : "Not Found\n");


    root = deleteNode(root, 20);
    cout << "After deleting 20:\n"; printTree(root); cout << '\n';


    root = deleteNode(root, 30);
    cout << "After deleting 30:\n"; printTree(root); cout << '\n';


    root = deleteNode(root, 50);
    cout << "After deleting 50:\n"; printTree(root); cout << '\n';


    cout << "Final Inorder: "; inorder(root); cout << '\n';


    freeTree(root);
    return 0;

}