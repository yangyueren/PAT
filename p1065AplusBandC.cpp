//
// Created by yryang on 2019/9/13.
//
//考虑c=0 ， 但是b=-2^64, c-b是2^64，但是溢出了


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
#include "unordered_map"
using namespace std;

int main(){
    long long a, b, c;
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%lld%lld%lld", &a,&b,&c);
        if(a==0 || b==0){
            if(a+b>c) printf("Case #%d: true\n",i);
            else printf("Case #%d: false\n",i);
        }
        else if(a>=0&&b>=0){
            if(c<=0){
                printf("Case #%d: true\n",i);
            } else{
                if(a>c-b) printf("Case #%d: true\n",i);
                else printf("Case #%d: false\n",i);
            }
        }
        else if(a<=0&&b<=0){
            if(c>=0){
                printf("Case #%d: false\n",i);
            } else{
                if(a>c-b) printf("Case #%d: true\n",i);
                else printf("Case #%d: false\n",i);
            }
        } else{
            if(a+b>c) printf("Case #%d: true\n",i);
            else printf("Case #%d: false\n",i);
        }
    }
}