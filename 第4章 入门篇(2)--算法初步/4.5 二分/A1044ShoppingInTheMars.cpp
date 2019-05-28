#include <iostream>
#include <vector>
using namespace std;

vector<int> sum, ans;
int n, m;

void binarySearch(int i, int &j, int &_sum) {
    int left = i;
    int right = n;
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (sum[mid] - sum[i-1] >= m) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    j = right;
    _sum = sum[j] - sum[i-1];
}


int main() {
    freopen("D:/in.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    sum.resize(n+1);
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &sum[i]);
        sum[i] += sum[i-1];
    }

    int min_sum = sum[n];
    for (int i = 1; i <= n; i++) {
        int j = 0, temp_sum = 0;
        binarySearch(i, j, temp_sum);
        if (temp_sum > min_sum) continue;
        if (temp_sum >= m) {
            if (temp_sum < min_sum) {
                ans.clear();
                min_sum = temp_sum;
            } 
            ans.push_back(i);
            ans.push_back(j);
        }
    }

    for (int i = 0; i < ans.size(); i+= 2) {
        printf("%d-%d\n", ans[i], ans[i+1]);
    }


    return 0;
}