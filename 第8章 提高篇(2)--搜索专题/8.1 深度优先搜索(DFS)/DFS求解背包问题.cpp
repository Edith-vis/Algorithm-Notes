#include <iostream>
using namespace std;

//法一:O(N^2)
#define maxn 30

int n, V, maxValue = 0;
int w[maxn], c[maxn];

void DFS(int index, int sumW, int sumC) {
    if (index == n) {
        if (sumW <= V && sumC > maxValue) {
            maxValue = sumC;
        } 
        return;
    }

    //选index号物品
    DFS(index+1, sumW+w[index], sumC+c[index]);
    //不选index号物品
    DFS(index+1, sumW, sumC);
}
//10
//[Done] exited with code=0 in 4.334 seconds

//法二：剪枝
void DFS1(int index, int sumW, int sumC) {
    if (index == n) return;

    //不选index号物品
    DFS1(index+1, sumW, sumC);

    //选index号物品
    if (sumW+w[index] <= V) {
        if (sumC+c[index] > maxValue) {
            maxValue = sumC+c[index];
        }
        DFS1(index+1, sumW+w[index], sumC+c[index]);
    }
}
//10
//[Done] exited with code=0 in 1.558 seconds

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%d", &n, &V);
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    DFS1(0, 0, 0);
    printf("%d", maxValue);

    return 0;
}