//建树、查找、插入、删除
#include <iostream>
using namespace std;

struct node {
    int data;
    node * left;
    node * right;

    node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

node * root = NULL;

//查找和修改
void search(node *root, int x, int value) {
    if(root == NULL) return;

    if (root->data == x) {
        root->data = value;
    }

    search(root->left, x, value);
    search(root->right, x, value);
}

//插入
void insert(node* &root, int x) {
    if (root == NULL) {
        root = new node(x);
        return;
    }
    insert(root->left, x);
    insert(root->right, x);
}

//创建
node* create(int data[], int n) {
    node * root = NULL;
    for (int i = 0; i < n; i++) {
        insert(root, data[i]);
    }
    return root;
}