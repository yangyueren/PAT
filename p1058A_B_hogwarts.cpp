//
// Created by yryang on 2019/9/11.
//

#include "iostream"
#include "stdio.h"
#include "stdlib.h"


//进位，carry
int main(){
    int a[3];
    int b[3];
    int c[3];
    scanf("%d.%d.%d",&a[0],&a[1],&a[2]);
    scanf("%d.%d.%d",&b[0],&b[1],&b[2]);
    int carry=0;
    c[2] = (a[2]+b[2])%29;
    carry = (a[2]+b[2])/29;
    c[1] = (a[1]+b[1]+carry)%17;
    carry = (a[1]+b[1]+carry)/17;
    c[0] = (a[0]+b[0]+carry);
    printf("%d.%d.%d\n", c[0],c[1],c[2]);

//  每三位输出一个逗号
//    int num[8]={1,2,3,4,5,6,7,8};
//    for (int i = 7; i >=0 ; --i) {
//        printf("%d", num[i]);
//        if(i!=0 && i%3==0) printf(",");
//    }
    return 0;
}