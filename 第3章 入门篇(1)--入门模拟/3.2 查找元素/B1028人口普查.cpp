#include <iostream>

struct person{
    char name[6];
    int yyyy, mm, dd;
} oldest, youngest, _left, _right, temp;

bool lessEqu(person a, person b) {//日期小于等于
    if (a.yyyy != b.yyyy) return a.yyyy <= b.yyyy;
    else if (a.mm != b.mm) return a.mm <= b.mm;
    else return a.dd <= b.dd;
}

bool moreEqu(person a, person b) {
    if (a.yyyy != b.yyyy) return a.yyyy >= b.yyyy;
    else if (a.mm != b.mm) return a.mm >= b.mm;
    else return a.dd >= b.dd;
}

void init() {
    youngest.yyyy = _left.yyyy = 1814;
    oldest.yyyy = _right.yyyy = 2014;
    youngest.mm = oldest.mm = _left.mm = _right.mm = 9;
    youngest.dd = oldest.dd = _left.dd = _right.dd = 6;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    init();
    int cnt = 0;//有效年龄的个数
    for (int i = 0; i < n; i++) {
        scanf("%s %d/%d/%d", temp.name, &temp.yyyy, &temp.mm, &temp.dd);
        //printf("%d/%d/%d\n", temp.yyyy, temp.mm, temp.dd);
        if (moreEqu(temp, _left) && lessEqu(temp, _right)) {
            cnt++;
            if (moreEqu(temp, youngest)) {
                youngest = temp;
            }
            if (lessEqu(temp, oldest)) {
                oldest = temp;
            }
        }
    }

    if (cnt == 0) {
        printf("0");
    } else {
        printf("%d %s %s", cnt, oldest.name, youngest.name);
    }
    return 0;
}