#include <iostream>
#include <string>
using namespace std;

int n;

string deal(string str, int& e) {
    while (str.length() != 0 && str[0] == '0') {
        str.erase(str.begin());
    }

    if (str[0] == '.') {//1型
        str.erase(str.begin());//删除小数点
        while (str.length() != 0 && str[0] == '0') {
            str.erase(str.begin());
            e--;
        }
    } else {//2型
        int k = 0;
        while (k < str.length() && str[k] != '.') {
            k++;
            e++;
        }
        //说明碰到了小数点
        if (k < str.length()) str.erase(str.begin()+k);
    }

    if (str.length() == 0) e = 0;//说明该数为0

    int k = 0, num = 0;
    string res = "";
    while (num < n) {
        if (k < str.length()) {
            res += str[k++];
        } else {
            res += "0";
        }
        num++;
    }
    return res;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    string str1, str2, str3, str4;
    cin >> n >> str1 >> str2;
    int e1 = 0, e2 = 0;
    str3 = deal(str1, e1);
    str4 = deal(str2, e2);
    if (str3 == str4 && e1 == e2) {
        cout << "YES 0." << str3 << "*10^" << e1 << endl;
    } else {
        cout << "NO 0." << str3 << "*10^" << e1 << " 0." << str4 << "*10^" << e2 << endl;
    }
    return 0;
}