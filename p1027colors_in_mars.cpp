//
// Created by yryang on 2019/9/11.
//

#include "iostream"
#include "string"
#include "stdlib.h"
#include "stdio.h"
#include "algorithm"
#include "vector"
using namespace std;
int main(){
    int k = 13;
    int a[6];
    string result = "";
    int tmp;
    int num=0;
    for (int i = 0; i < 3; ++i) {
        scanf("%d",&tmp);
        do{
            a[num++] = tmp%k;
            tmp /= k;
        }while(tmp!=0);
        if(num%2==1) a[num++] = 0;
    }
    int b[6]={1,0,3,2,5,4};
    string re="#";
    for (int j = 0; j < 6; ++j) {
        int c = a[b[j]];
        if(c==10) re+="A";
        if(c==11) re+="B";
        if(c==12) re+="C";
        if(c<10) re+= c+'0';
    }
    cout << re<<endl;

    return 0;
}