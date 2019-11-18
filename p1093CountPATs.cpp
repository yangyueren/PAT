//
// Created by yryang on 2019/9/11.
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
using namespace std;

char s[100005];
int num=0;

//改用long long
long long p=0;
long long pa=0;
long long pat=0;

int main(){
    char a;

    do{
        scanf("%c",&a);
        if(a=='\n') break;
        if(a=='P') p++;
        if(a=='A') pa+=p;
        if(a=='T') pat+=pa;

    }while (a!='\n');
    printf("%d\n", pat%1000000007);



//    scanf("%s", s);
//    int len=strlen(s);
//    for (int i = 0; i < len-2; ++i) {
//        if(s[i] != 'P') continue;
//        for (int j = i+1; j < len-1; ++j) {
//            if(s[j] != 'A') continue;
//            for (int k = j+1; k < len; ++k) {
//                if (s[k] != 'T') continue;
//                else num++;
//            }
//        }
//    }
//    printf("%d\n",num%1000000007);
}