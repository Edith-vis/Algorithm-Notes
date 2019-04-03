#include <cstdio>
#include <vector>
using namespace std;
#define maxn 101

//从序列A中的n个数选择k个数使得他们和为x，最大平方和为maxSumSqu
int n, k, x, maxSumSqu = -1;
int A[maxn];

//temp存储临时方案，ans存储当前最优方案
vector<int> temp, ans;

void DFS(int index, int nowK, int sum, int sumSqu) {
    if (nowK == k && sum == x) {
        if (sumSqu > maxSumSqu) {
            maxSumSqu = sumSqu;
            ans = temp;
        }
        return;
    }

    if (index == n || sum > x || nowK > k) return;


    //选index号
    temp.push_back(A[index]);
    DFS(index+1, nowK+1, sum+A[index], sumSqu+A[index]*A[index]);
    temp.pop_back();

    //不选index号
    DFS(index+1, nowK, sum, sumSqu);
}