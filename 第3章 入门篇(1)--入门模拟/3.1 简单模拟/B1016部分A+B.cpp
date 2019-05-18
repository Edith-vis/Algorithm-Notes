#include <iostream>
#include <cstring>
using namespace std;

string A, B;
int da, db, pa = 0, pb = 0;

int main() {
    freopen("D:/in.txt", "r", stdin);
    cin >> A >> da >> B >> db;

    int countA = 0, countB = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] - '0' == da) {
            countA++;
        }
    }

    for (int i = 0; i < B.size(); i++) {
        if (B[i] - '0' == db) {
            countB++;
        }
    }


    for (int i = 0; i < countA; i++) {
        pa = 10*pa + da;
    }

    for (int i = 0; i < countB; i++) {
        pb = 10*pb + db;
    }

    printf("%d", pa+pb);
    
    return 0;
}