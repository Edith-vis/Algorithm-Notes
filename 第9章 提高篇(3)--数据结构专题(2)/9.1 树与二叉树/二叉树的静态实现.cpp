#include <iostream>
#include <vector>
using namespace std;

#define maxn 101

struct node{
    int data;
    vector<node> child;
} Node[maxn];

//
int index = 0;
int newNode(int x) {
    Node[index].data = x;
    Node[index].child.clear();
    return index++; 
}