#include <iostream>
#include <string>
using namespace std;

int n;//精度

string deal(string s, int &e) {
    int k = 0;
    while (s.length() > 0 && s[0] == '0') {
        s.erase(s.begin());
    }

    //计算e 去掉碍事的0和.
    if (s[0] == '.') {//形如0.a1a2a3...
        s.erase(s.begin());
        while (s.length() > 0 && s[0] == '0') {
            s.erase(s.begin());
            e--;
        }
    } else {//形如b1b2b3.a1a2a3...
        while (k < s.length() && s[k] != '.') {
            k++;
            e++;
        }

        if (k < s.length()) s.erase(s.begin() + k);
    }

    if (s.length() == 0) e = 0;//去除前导0和小数点后长度为0 说明该数为0
    
    int num = 0; k = 0;
    string res;
    while (num < n) {
        if (k < s.length()) res += s[k++];
        else res += '0';
        num++;
    }
    return res;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    string s1, s2, s3, s4;
    cin >> n >> s1 >> s2;
    int e1 = 0, e2 = 0;
    s3 = deal(s1, e1);
    s4 = deal(s2, e2);
    if (s3 == s4 && e1 == e2) {
        cout << "YES 0." << s3 << "*10^" << e1;
    } else {
        cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2;
    }

    return 0;
}