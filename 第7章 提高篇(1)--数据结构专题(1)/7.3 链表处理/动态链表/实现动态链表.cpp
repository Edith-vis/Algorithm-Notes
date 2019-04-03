#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* create(int Array[]) {
    node* head = new node;
    head->next = NULL;

    node* pre = head;
    for (int i = 0; i < 5; i++) {
        node* p = new node;
        
        p->data = Array[i];
        p->next = NULL;

        pre->next = p;
        pre = p;
    }
    return head;
}

int search(node* head, int x) {
    int cnt = 0;
    node* p = head->next;
    while (p != NULL) {
        if (p->data == x) {
            cnt++;
        }
        p = p->next;
    }
    return cnt;
}

void insert(node* head, int pos, int x) {
    node* pre = head;
    for (int i = 0; i < pos-1; i++) {
        pre = pre->next;
    }
    node* p = new node;
    p->data = x;
    p->next = pre->next;
    pre->next = p;
}

void del(node* head, int x) {
    node* p = head->next;
    node* pre = head;
    while (p != NULL) {
        if (p->data == x) {
            pre->next = p->next;
            delete(p);
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
        
    }
}