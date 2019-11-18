//
// Created by yryang on 2019/9/15.
//

//要用数论方法：假设第k位为1，看看有多少个数字。

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


int N;

int cnt=0;
int total=0;
void dfs(int num){
    if(num <= N){
        total += cnt;
    }
    if(num > N) return;

    for (int i = 0; i < 10; ++i) {
        if(num*10+i<=N){
            if(i==1) cnt++;
            dfs(num*10 + i);
            if(i==1) cnt--;
        }
    }
}
int main(){
    scanf("%d",&N);
    for (int i = 1; i < 10; ++i) {
        if(i==1) cnt++;
        dfs(i);
        if(i==1) cnt--;
    }
    cout << total;
}