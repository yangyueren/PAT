//
// Created by yryang on 2019/9/10.
//

#include <iostream>
#include "math.h"
#include "vector"
#include "stdio.h"
#include "stdlib.h"
#include "set"
#include "algorithm"
using namespace std;


//排序后pivot的位置不变，且左边比他小。
int main(){
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    int result[100006];
    int leftmax = INT32_MIN;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    int cnt=0;
    for (int j = 0; j < n; ++j) {
        if(b[j] == a[j] && a[j] > leftmax){
            result[cnt++] = a[j];
        }
        if(a[j] > leftmax){
            leftmax = a[j];
        }
    }
    printf("%d\n", cnt);
    for (int k = 0; k < cnt; ++k) {
        if(k!=0){
            printf(" ");
        }
        printf("%d",result[k]);
    }
    printf("\n");
    return 0;
}