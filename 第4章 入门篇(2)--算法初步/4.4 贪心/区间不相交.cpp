#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 110
struct interval{
    int x, y;
    bool operator < (const interval &A) const {
        return (x != A.x) ? x > A.x : y < A.y; 
    }
}I[maxn];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF){
        for (int i = 0; i < n; i++){
            scanf("%d %d", &I[i].x, &I[i].y);
        }
        sort(I, I+n);
        int ans = 1;
        int lastX = I[0].x;
        for (int i = 1; i < n; i++) {
            if (I[i].y <= lastX) {
                lastX = I[i].x;
                ans++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}