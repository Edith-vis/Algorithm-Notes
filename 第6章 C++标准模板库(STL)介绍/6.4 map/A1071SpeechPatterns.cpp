#include <iostream>
#include <map>
#include <string>
using namespace std;

bool isValid(char &c) {
    if (c >= '0' && c <= '9') return true;
    if (c >= 'a' && c <= 'z') return true;
    if (c >= 'A' && c <= 'Z') return true;
    
    return false;
}

map<string, int> arr;

int main() {
    freopen("D:/in.txt", "r", stdin);
    string str;
    getline(cin, str);

    int i = 0;
    while (i < str.length()) {
        string word;
        while (i < str.length() && isValid(str[i])) {
            if (str[i] >= 'A' && str[i] <= 'Z') str[i] = str[i] - 'A' + 'a';
            word += str[i];
            i++;
        }
        if (word != "") {
            if (arr.find(word) == arr.end()) arr[word] = 1;
            else arr[word]++;
        }
        while (i < str.length() && !isValid(str[i])){
            i++;
        }
    }

    string ans;
    int _max = 0;
    //map内部是按字典序的
    for (auto it = arr.begin(); it != arr.end(); it++) {
        if (it->second > _max) {
            _max = it->second;
            ans = it->first;
        }
    }

    cout << ans << " " << _max << endl;

    return 0;
}