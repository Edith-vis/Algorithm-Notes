#include <iostream>
using namespace std;

struct node {
    int v;
    int height;
    node* left;
    node* right;
};

node* newNode(int v) {
    node* Node = new node;
    Node->v = v;
    Node->height = 1;
    Node->left = Node->right = NULL;
    return Node;
}

int getHeight(node* root) {
    if(root == NULL) return 0;
    return root->height;
}

int getBalanceFactor(node* root) {
    return getHeight(root->left) - getHeight(root->right);
}

void updateHeight(node* root) {
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

void L(node* &root) {
    node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(node* &root) {
    node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(node* &root, int v) {
    if (root == NULL) {
        root = newNode(v);
        return;
    }

    if (v < root->v) {
        insert(root->left, v);
        updateHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->left) == 1) {
                R(root);
            } else if (getBalanceFactor(root->left) == -1) {
                L(root->left);
                R(root);
            }
        }
    } else {
        insert(root->right, v);
        updateHeight(root);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->right) == -1) {
                L(root);
            } else if (getBalanceFactor(root->right) == 1) {
                R(root->right);
                L(root);
            }
        }
    }
}


int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    node* root = NULL;
    int v;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v);
        insert(root, v);
    }
    printf("%d", root->v);
    return 0;
}