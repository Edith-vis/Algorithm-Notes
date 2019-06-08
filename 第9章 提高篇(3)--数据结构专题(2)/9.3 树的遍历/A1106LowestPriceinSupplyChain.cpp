#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 100010;
const double INF = 1e12;
int n;
double p, r;
vector<int> Node[maxn];

double min_price = INF;
int min_num = 0;
void DFS(int id, int depth) {
    if (Node[id].size() == 0) {
        double price = p * pow(1 + r, depth);
        if (price < min_price) {
            min_price = price;
            min_num = 1;
        } else if (price == min_price) {
            min_num++;
        }
        return;
    }

    for (int i = 0; i < Node[id].size(); i++) {
        DFS(Node[id][i], depth + 1);
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%lf%lf", &n, &p, &r);
    r = r / 100.0;

    int k, child;
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        if (k != 0) {
            for (int j = 0; j < k; j++) {
                scanf("%d", &child);
                Node[i].push_back(child);
            }
        }
    }

    DFS(0, 0);
    printf("%.4lf %d\n", min_price, min_num);

    return 0;
}