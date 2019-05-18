#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long LL;

const LL MOD = 1000000007;//10的9次方 计算hash值时的模数
const LL P = 10000019;//10的7次方 计算hash值时的进制数
const LL MAXN = 1010;//字符串最长长度

LL powP[MAXN];//存放P的i次方 % MOD的值
LL H1[MAXN] = {0};//存放str1的hash值
LL H2[MAXN] = {0};//存放str2的hash值

//pr存放str的所有<子串hash值，子串长度>
vector<pair<int, int> > pr1, pr2;

//初始化powP函数
void init(int len) {
    powP[0] = 1;
    for (int i = 1; i <= len; i++) {
        powP[i] = (powP[i-1] * P) % MOD;
    }
}

//计算字符串str的hash值
void calH(LL H[], string &str) {
    H[0] = str[0];
    for (int i = 1; i < str.length(); i++) {
        H[i] = (H[i-1] * P + str[i]) % MOD;
    }
}

//计算单个子串的hash值
int calSingleSubH(LL H[], int i, int j) {
    if (i == 0) return H[j];
    return ((H[j] - H[i-1] * powP[j-i+1]) % MOD + MOD) % MOD;
}

//计算所有子串的hash值
void calSubH(LL H[], int len, vector<pair<int, int> > &pr) {
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            int hashValue = calSingleSubH(H, i, j);
            pr.push_back(make_pair(hashValue, j-i+1));
        }
    }
}

//计算pr1和pr2中相同的hash值，维护最大长度
int getMax() {
    int ans = 0;
    for (int i = 0; i < pr1.size(); i++) {
        for (int j = 0; j < pr2.size(); j++) {
            if (pr1[i].first == pr2[j].first) {
                ans = max(ans, pr1[i].second);
            }
        }
    }
    return ans;
}


int main() {
    freopen("D:/in.txt", "r", stdin);
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    init(max(str1.length(), str2.length()));
    calH(H1, str1);
    calH(H2, str2);
    calSubH(H1, str1.length(), pr1);
    calSubH(H2, str2.length(), pr2);

    printf("%d\n", getMax());

    return 0;
}