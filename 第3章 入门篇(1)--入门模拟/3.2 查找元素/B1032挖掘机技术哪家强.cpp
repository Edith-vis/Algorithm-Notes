#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int school[100010] = {0}; //段错误：数组开小了

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    int m = 0;
    for (int i = 0; i < n; i++) {
        int id, score;
        scanf("%d %d", &id, &score);
        if (id > m) m = id;
        school[id] += score;
    }
    
    int max_score = 0, max_id = 0;
    for (int i = 1; i <= m; i++) {
        if (max_score < school[i]) {
            max_id = i;
            max_score = school[i];
        }
    }
    printf("%d %d", max_id, max_score);
    return 0;
}