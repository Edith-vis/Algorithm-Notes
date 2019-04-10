#include <iostream>
#include <vector>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int x) {
        data = x;
        left = right = NULL;
    }
};

int n;
vector<int> origin, pre, post, preM, postM;

void insert(node* &root, int x) {
    if (root == NULL) {
        root = new node(x);
        return;
    }

    if (x < root->data) insert(root->left, x);
    else insert(root->right, x);
}

void preOrder(node * root, vector<int> &vi) {
    if (root == NULL) return;
    vi.push_back(root->data);
    preOrder(root->left, vi);
    preOrder(root->right, vi);
}

void preOrderMirror(node *root, vector<int> &vi) {
    if (root == NULL) return;
    vi.push_back(root->data);
    preOrderMirror(root->right, vi);
    preOrderMirror(root->left, vi);
}

void postOrder(node* root, vector<int> &vi) {
    if (root == NULL) return;

    postOrder(root->left, vi);
    postOrder(root->right, vi);
    vi.push_back(root->data);
}

void postOrderMirror(node* root, vector<int> &vi) {
    if (root == NULL) return;

    postOrderMirror(root->right, vi);
    postOrderMirror(root->left, vi);
    vi.push_back(root->data);
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d", &n);

    node * root = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        origin.push_back(data);
        insert(root, data);
    }

    preOrder(root, pre);
    preOrderMirror(root, preM);
    if (pre == origin) {
        printf("YES\n");
        postOrder(root, post);
        for (int i = 0; i < n; i++) {
            if (i != 0) printf(" ");
            printf("%d", post[i]);
        }
    } else if (preM == origin) {
        printf("YES\n");
        postOrderMirror(root, postM);
        for (int i = 0; i < n; i++) {
            if (i != 0) printf(" ");
            printf("%d", postM[i]);
        }
    } else {
        printf("NO\n");
    }
    return 0;
}