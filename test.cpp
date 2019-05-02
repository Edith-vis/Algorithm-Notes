#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode * next;

    ListNode(int _data) {
        data = _data;
        next = NULL;
    }
};





int main() {
    ListNode * res;
    ListNode head(0);
    res = &head;
    while (l1 && l2) {
        temp = l1->data + l2->data + carry;
        res->next = new ListNode(temp%10);
        res = res->next;
    }
}