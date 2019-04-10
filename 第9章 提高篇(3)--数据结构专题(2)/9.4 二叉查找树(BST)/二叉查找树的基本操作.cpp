#include <iostream>
using namespace std;

//查找、插入、建树、删除
struct node {
    int data;
    node* left;
    node* right;

    node(int x) {
        data = x;
        left = right = NULL;
    }
};

//查找
void search(node* root, int x) {
    if (root == NULL) {
        printf("Failed\n");
        return;
    }
    if (root->data == x) {
        printf("%d\n", root->data);
        return;
    } else if (x < root->data){
        search(root->left, x);
    } else {
        search(root->right, x);
    }
}

//插入：查找失败的就是插入的地方
void insert(node* &root, int x) {
    if (root == NULL) {
        root = new node(x);
        return;
    }

    if (x == root->data) {
        return;
    }else if (x < root->data) {
        insert(root->left, x);
    } else {
        insert(root->right, x);
    }
}

//建立
node * create(int data[], int n) {
    node * root = NULL;
    for (int i = 0; i < n; i++) {
        insert(root, data[i]);
    }
    return root;
}

//删除
//寻找以root为根结点的树中的最大权值结点
node* findMax(node* root) {
    while (root->right) {
        root = root->right;
    }
    return root;
}
//寻找以root为根结点都得树中的最小权值结点
node* findMin(node* root) {
    while(root->left) {
        root = root->left;
    }
    return root;
}

void deleteNode(node* &root, int x) {
    if (root == NULL) return;

    if (root->data == x) {
        if (root->left == NULL && root->right == NULL) {
            root = NULL;
        } else if (root->left == NULL) {
            node* next = findMax(root->right);
            root->data = next->data;
            deleteNode(root->right, next->data);
        } else {
            node* pre = findMin(root->left);
            root->data = pre->data;
            deleteNode(root->left, pre->data); 
        }
    } else if (x < root->data) {
        deleteNode(root->left, x);
    } else {
        deleteNode(root->right, x);
    }
}