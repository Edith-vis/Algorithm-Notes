#include <iostream>
#include <set>
using namespace std;

set<int> numbers[60];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);
        for (int j = 1; j <= num; j++) {
            int t;
            scanf("%d", &t);
            numbers[i].insert(t);
        }
    }

    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        int totalNUM = numbers[b].size();
        int sameNUM = 0;
        for (auto it = numbers[a].begin(); it != numbers[a].end(); it++) {
            if (numbers[b].find(*it) != numbers[b].end()) {
                sameNUM++;
            } else {
                totalNUM++;
            }
        }
        printf("%.1lf%\n", 100.0 * sameNUM / totalNUM);
    }

    return 0;
}