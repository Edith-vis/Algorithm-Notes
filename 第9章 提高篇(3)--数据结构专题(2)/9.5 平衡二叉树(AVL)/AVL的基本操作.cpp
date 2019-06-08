#include <iostream>
#include <cmath>
using namespace std;

struct node{
    int data, height;
    node *left, *right;

    node(int x) {
        data = x;
        left = right = NULL;
        height = 1;
    }
};

int getHeight(node * root) {
    if (root == NULL) return 0;
    else return root->height;
}

void updateHeight(node * root) {
    root->height = max(getHeight(root->left), getHeight(root->right))+1;
}

//平衡因子
int getBalanceFactor(node * root) {
    return getHeight(root->left) - getHeight(root->right);//左减右
}

//插入操作！！！
//左旋
void L(node * root) {
    node * temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

//右旋
void R(node * root) {
    node * temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(node * root, int x) {
    if (root == NULL) {
        root = new node(x);
        return;
    }

    if (x < root->data) {
        insert(root->left, x);
        updateHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->left) == 1) {
                R(root);
            } else if (getBalanceFactor(root->left) == -1) {
                L(root->left);
                R(root);
            }
        }
    } else if (x > root->data) {
        insert(root->right, x);
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