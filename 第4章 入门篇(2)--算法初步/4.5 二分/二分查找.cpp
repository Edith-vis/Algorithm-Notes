#include <iostream>
using namespace std;

//A[]为严格递增序列，left为二分下界，right为二分上界
//二分区间为左闭右闭的[left, right]，传入的初值为[0, n-1]
int binarySearch(int A[], int left, int right, int t) {
    int mid;
    while (left <= right) {
        mid = (left+right)/2;
        if (A[mid] == t) {
            return mid;
        } else if (A[mid] < t) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

//A[]为递增序列，x为欲查询的数
//函数返回第一个大于等于x的元素的位置
//二分上下界为左闭右闭的[left, right]，传入的初值为[0, n]
int lower_bound(int A[], int left, int right, int x) {
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (A[mid] >= x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

//A[]为递增序列，x为欲查询的数
//函数返回第一个大于x的元素的位置
//二分上下界为左闭右闭的[left, right]，传入的初值为[0, n]
int upper_bound(int A[], int left, int right, int x){
    int mid;
    while (left < right) {
        mid = (left+right)/2;
        if (A[mid] > x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

//左闭右闭区间 找第一个满足某条件的位置 模板
int solve(int left, int right) {
    int mid;
    while (left < right) {
        mid = (left+right)/2;
        if (条件满足) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

//左开右闭区间 找第一个满足某条件的位置 模板
int solve2(int left, int right) {
    int mid;
    while (left+1 < right) {
        mid = (left+right)/2;
        if (条件满足) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return right;
}
int main() {

    return 0;
}