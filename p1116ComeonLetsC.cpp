//
// Created by yryang on 2019/9/14.
//

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
#include "algorithm"
using namespace std;

int ranky[10005];

int isprime(int n){
    if(n<2) return 0;
    if(n==2) return 1;
    for (int i = 2; i*i <= n; ++i) {
        if(n%i ==0) return 0;
    }
    return 1;
}
int main(){
    int N;
    scanf("%d",&N);
    for (int i = 1; i <= N; ++i) {
        int a;
        scanf("%d",&a);
        ranky[a] = i;
    }
    int K;
    scanf("%d",&K);
    for (int j = 0; j < K; ++j) {
        int a;
        scanf("%d",&a);
        int award = ranky[a];
        if(award == 0) printf("%04d: Are you kidding?\n", a);
        else if(award == -1) printf("%04d: Checked\n", a);
        else if(award == 1) printf("%04d: Mystery Award\n", a);
        else if(isprime(award)) printf("%04d: Minion\n", a);
        else printf("%04d: Chocolate\n", a);
        if(ranky[a] != 0){
            ranky[a] = -1;
        }

    }
    return 0;
}