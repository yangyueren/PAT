//
// Created by yryang on 2019/9/11.
//

#include "iostream"
#include "string"
#include "stdlib.h"
#include "stdio.h"
#include "map"
#include "vector"
#include "set"
#include "math.h"
using namespace std;


int factors[1000];
int N;
int num=0;
void cal(int a){
    int sqrtnum = sqrt(a)+1;
    int begin, maxnum=-1;
    int nownum;
    int mul;
    for (int i = 2; i <= sqrtnum; ++i) {
        nownum=0;
        mul=i;
        int shao=i;
        while (a%mul==0){
            nownum++;
            shao+=1;
            mul*=shao;
        }
        if(nownum>maxnum){
            maxnum=nownum;
            begin=i;
        }
    }


    if(maxnum==0){
        printf("%d\n", maxnum+1);
        printf("%d",N);
    } else{
        printf("%d\n", maxnum);
        mul=begin;
        int i=0;
        while (a%mul==0){
            if(i!=0) printf("*");
            i++;
            printf("%d", begin);
            begin=begin+1;
            mul*=begin;
        }
    }

}
int main(){
    scanf("%d", &N);
    cal(N);
}