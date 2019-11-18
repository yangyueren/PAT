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
#include "string"
#include "queue"
using namespace std;

int ksm(int a, int b){
    int ans = 1, base = a;
    while(b!=0){
        if((b&1)!=0){
            ans*=base;
        }
        base*=base;
        b = b>>1;
    }
    return ans;
}


int N, K, P;

int path[500];
int cnt = 0;


vector<vector<int>> result;
int recurve(int total){
    cnt++;

    if(total == 0 && cnt==K+1) {
        return 1;
    }
    if(cnt > K) return 0;
    int now = cnt;
    for (int i = total; i > 0; --i) {
        cnt = now;
        if(i > total) return 0;
        int re = recurve(total-ksm(i,P));

        if(re!=0){
            path[now] = i;
            return 1;
        }
    }
    return 0;
}
int main(){

    path[0] = 5;

    scanf("%d%d%d",&N,&K,&P);
    int flag = recurve(N);

    if(flag){
        for (int i = 1; i < K; ++i) {
            cout << path[i] << " ";
        }
        cout << path[K];
    }else{
        printf("Impossible\n");
    }
}