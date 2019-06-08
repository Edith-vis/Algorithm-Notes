#include <iostream>
#include <vector>
using namespace std;

vector<int> origin, pre, preM, post, postM;

struct node {
    int data;
    node *left;
    node *right;
    node (int _data) {
        data = _data;
        left = NULL;
        right = NULL;
    }
};

void insert(node* &root, int _data) {
    if (root == NULL) {
        root = new node(_data);
        return;
    }

    if (_data >= root->data) insert(root->right, _data);
    else insert(root->left, _data);
}

void preOrder(node* root) {
    if (root == NULL) return;
    pre.push_back(root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void preMirrorOrder(node* root) {
    if (root == NULL) return;
    preM.push_back(root->data);
    preMirrorOrder(root->right);
    preMirrorOrder(root->left);
}

void postOrder(node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    post.push_back(root->data);
}

void postMirrorOrder(node* root) {
    if (root == NULL) return;
    postMirrorOrder(root->right);
    postMirrorOrder(root->left);
    postM.push_back(root->data);
}


int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int data;
    node* root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        origin.push_back(data);
        insert(root, data);
    }

    preOrder(root);
    preMirrorOrder(root);

    if (pre == origin) {
        printf("YES\n");
        postOrder(root);
        for (int i = 0; i < n; i++) {
            if (i != 0) printf(" ");
            printf("%d", post[i]);
        }
    } else if (preM == origin) {
        printf("YES\n");
        postMirrorOrder(root);
        for (int i = 0; i < n; i++) {
            if (i != 0) printf(" ");
            printf("%d", postM[i]);
        }        
    } else {
        printf("NO\n");
    }

    return 0;
}