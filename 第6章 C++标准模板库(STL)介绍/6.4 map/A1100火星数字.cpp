#include <iostream>
#include <map>
using namespace std;

string unitDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tenDigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

string numToStr[170];//数字->火星文
map<string, int> strToNum;//火星文->数字

//打表
void init() {
    for (int i = 0; i < 13; i++) {
        //个位为[0, 12],十位为0
        numToStr[i] = unitDigit[i];
        strToNum[unitDigit[i]] = i;
        //十位为[0, 12],个位为0
        numToStr[i * 13] = tenDigit[i];
        strToNum[tenDigit[i]] = i * 13; 
    }

    for (int i = 1; i < 13; i++) {//十位
        for (int j = 1; j < 13; j++) {//个位
            string str = tenDigit[i] + " " + unitDigit[j];
            numToStr[i * 13 + j] = str;
            strToNum[str] = i * 13 + j;
        }
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d" , &n);
    getchar();
    //printf("%d\n", n);

    init();

    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        //cout << str << "-----" <<endl;
        if (str[0] >= '0' && str[0] <= '9') {
            int num = 0;
            for (int j = 0; j < str.length(); j++) {
                num = num * 10 + str[j] - '0';
            }
            //printf("%d\n", num);
            cout << numToStr[num] << endl;
        } else {
            cout << strToNum[str] << endl;
        }

    }

    return 0;
}