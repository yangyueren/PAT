//
// Created by yryang on 2019/9/12.
//

//di = (h(key) + i*i)%m   0<=i<=m-1
//结束的条件：1 当前探测为0  2 遍历完了tsize  3 查找到了key

#include "iostream"
#include "string.h"
#include "string"
#include "stdlib.h"
#include "stdio.h"
#include "map"
#include "vector"
#include "set"
#include "math.h"
#include "queue"
using namespace std;

int isprime(int n){
    if(n<2) return 0;
    if(n==2) return 1;
    for (int i = 2; i*i <= n ; ++i) {
        if(n%i ==0) {
            return 0;
        }

    }
    return 1;
}


int tsize;
int h[10010];
int N;
int sum=0;
//succ 1, fail 0
int insert(int n){
    for (int i = 0; i < tsize; ++i) {
        int loc = (n + i*i)%tsize;
        if(h[loc] == 0){
            h[loc] = n;
            return 1;
        }
    }
    return 0;
}
int search(int n){
    int s=0;
    for (int i = 0; i <= tsize; ++i) {
        s++;
        int loc = (n + i*i)%tsize;
        if(h[loc] == n || h[loc]==0){
            return s;
        }
    }
    return s;
}
int main(){
    int msize, N, M;
    scanf("%d%d%d", &msize, &N,&M);
    for (int i = msize; i>0 ; ++i) {
        if(isprime(i) == 1){
            tsize = i;
            break;
        }
    }

    int now;
    for (int j = 0; j < N; ++j) {
        scanf("%d", &now);
        if(insert(now) == 0){
            printf("%d cannot be inserted.\n", now);
        }
    }
    for (int k = 0; k < M; ++k) {
        scanf("%d", &now);
        sum += search(now);
    }
//    cout << sum;
    double av = (sum*1.0)/M;
    printf("%.1lf\n", av);

    return 0;
}