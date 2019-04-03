#include <cstdio>

int school[100001] = {0};

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, schID, score;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &schID, &score);
        school[schID] += score;
    }

    int sch = 0, maxScore = -1;
    for (int i = 1; i <= n; i++) {
        if (school[i] > maxScore) {
            maxScore = school[i];
            sch = i;
        }
    }
    printf("%d %d\n", sch, maxScore);    
    return 0;
}