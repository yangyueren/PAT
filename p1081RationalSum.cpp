//
// Created by yryang on 2019/9/13.
//

//输出是重点，考虑0的情况

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
long long nume=0;
long long deno = 1;

long long gcd(long long a,  long long b){
    return b == 0 ? abs(a) : gcd(b, a % b);
}
void cal(long long a, long long b){
    long long dd = gcd(abs(a), abs(b));
    a = a/ dd;
    b = b/dd;
    long long fenzi = nume*b+a*deno;
    long long fenmu = deno*b;

    long long div = gcd( abs(fenzi), abs(fenmu));
    nume = fenzi / div;
    deno = fenmu / div;
}
int main(){

    scanf("%d", &N);


    for (int i = 0; i < N; ++i) {
        long long a, b;
        scanf("%lld/%lld",&a,&b);
        cal(a, b);
    }
    long long suma = nume;
    long long sumb = deno;
    long long integer = suma / sumb;
    suma = suma - (sumb * integer);
    if(integer != 0) {
        printf("%lld", integer);
        if(suma != 0) printf(" ");
    }
    if(suma != 0)
        printf("%lld/%lld", suma, sumb);
    if(integer == 0 && suma == 0)
        printf("0");
//    if(nume % deno ==0) printf("%lld\n", nume/deno);
//    else if(nume / deno == 0) printf("%lld/%lld", nume/deno, nume%deno, deno);
//    else printf("%lld %lld/%lld", nume/deno, nume%deno, deno);
    return 0;
}