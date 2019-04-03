#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>
using namespace std;

struct node{
    double num;
    char op;
    bool flag;//true为操作数
};

string str;
stack<node> s;//先做操作符栈，后做操作数栈
queue<node> q;//存储后缀表达式
map<char, int> op;//操作符的优先级

void change() {//stack存储操作符
    node temp;
    for (int i = 0; i < str.length();) {
        if (str[i] >= '0' && str[i] <= '9') {//是操作数
            temp.flag = true;

            temp.num = str[i++]-'0';
            while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
                temp.num = temp.num*10 + (str[i++]-'0');
            }

            q.push(temp);//将操作数压入后缀表达式队列里
        } else {
            temp.flag = false;
            temp.op = str[i];

            //只要操作符栈顶的元素优先级比当前操作符优先级高
            //就把操作符栈顶元素弹出到后缀表达式队列里
            while (!s.empty() && op[str[i]] <= op[s.top().op]) {
                q.push(s.top());
                s.pop();
            }
            
            s.push(temp);//将操作符压入操作符栈中
            i++;
        }
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    //结束之后栈是空的
}

double cal() {//stack存储操作数
    double temp1, temp2;//存储两个操作数
    node cur, temp;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur.flag == true) {//是操作数
            s.push(cur);
        } else {//是操作符
            temp2 = s.top().num;//先弹出的是第二操作数
            s.pop();
            temp1 = s.top().num;//后弹出第一操作数
            s.pop();
            temp.flag = true;
            if (cur.op == '+') temp.num = temp1+temp2;
            else if (cur.op == '-') temp.num = temp1-temp2;
            else if (cur.op == '*') temp.num = temp1*temp2;
            else temp.num = temp1/temp2;
            s.push(temp);
        }
    }
    return s.top().num;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    while (getline(cin, str), str != "0") {
        for (string::iterator it = str.begin(); it != str.end(); it++) {
            if (*it == ' ') str.erase(it);
        }
        while (!s.empty()) s.pop();
        change();
        printf("%.2f\n", cal());
    }
    
    return 0;
}