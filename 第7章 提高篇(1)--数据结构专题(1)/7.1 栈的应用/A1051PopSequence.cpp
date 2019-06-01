#include <iostream>
#include <stack>
using namespace std;

#define maxn 1010
int arr[maxn];//题目给的出栈序列
stack<int> st;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int m, n, T;
    scanf("%d %d %d", &m, &n, &T);

    while (T--) {
        while (st.empty() == false) {
            st.pop();
        }

        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
        }

        int current = 1;
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            st.push(i);
            if (st.size() > m) {
                flag = false;
                break;
            }

            while (!st.empty() && st.top() == arr[current]) {
                st.pop();
                current++;
            }
        }

        if (st.empty() == true && flag == true) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }

    }

    return 0;
}