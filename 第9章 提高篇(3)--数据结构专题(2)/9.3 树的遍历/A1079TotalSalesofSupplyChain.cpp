#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 100010;

struct node {
    double amount;
    vector<int> child;
} Node[maxn];

int n;
double p, r;

double ans = 0.0;

void DFS(int id, int depth) {
    if (Node[id].child.size() == 0) {
        ans += Node[id].amount * pow(1+r, depth);
        return;
    }

    for (int i = 0; i < Node[id].child.size(); i++) {
        DFS(Node[id].child[i], depth + 1);
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%lf%lf", &n, &p, &r);
    r = r/100.0;

    int k, id;
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        if (k == 0) {
            scanf("%lf", &Node[i].amount);
        } else {
            for (int j = 0; j < k; j++) {
                scanf("%d", &id);
                Node[i].child.push_back(id);
            }
        }
    }

    DFS(0, 0);
    printf("%.1lf", p*ans);

    return 0;
}