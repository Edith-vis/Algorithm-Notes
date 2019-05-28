#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 10010

string input[maxn];

bool cmp(string a, string b) {
    return a+b < b+a;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    sort(input, input + n, cmp);

    string ans;
    for (int i = 0; i < n; i++) {
        ans += input[i];
    }

    while (ans[0] == '0' && ans.size() != 0) {
        ans.erase(ans.begin());
    }
    if (ans.size() == 0) cout << 0;
    else cout << ans;

    return 0;
}