#include <iostream>
#include <vector>
using namespace std;

int n, k, p;

vector<int> _power;

int power(int x) {
    int ans = 1;
    for (int i = 0; i < p; i++) {
        ans *= x;
    }
    return ans;
}

void init() {
    int i = 0, temp = 0;
    while (temp <= n) {
        _power.push_back(temp);
        temp = power(++i);
    }
}

vector<int> temp, ans;

int maxSum = -1;
void DFS(int index, int sum, int nowK, int sumSqu) {
    if (sum == n && nowK == k) {
        if (sumSqu > maxSum) {
            maxSum = sumSqu;
            ans = temp;
        }
        return;
    }

    if (sum > n || nowK > k) return;

    if (index > 0) {

        temp.push_back(index);
        DFS(index, sum + _power[index], nowK + 1, sumSqu + index);
        temp.pop_back();

        DFS(index-1, sum, nowK, sumSqu);
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    
    scanf("%d%d%d", &n, &k, &p);

    init();

    DFS(_power.size() - 1, 0, 0, 0);

    if (maxSum == -1) printf("Impossible\n");
    else {
        printf("%d = ", n);
        for (int i = 0; i < ans.size(); i++) {
            if (i != 0) printf(" + ");
            printf("%d^%d", ans[i], p);
        }
    }

    return 0;
}