//
// Created by yryang on 2019/9/15.
//

#include "stdio.h"
#include "stdlib.h"
#include "string"
#include "string.h"
#include "set"
#include "map"
#include "vector"
#include "algorithm"
#include "unordered_map"
#include "iostream"
using namespace std;

long long z;
int main(){
    int N;
    scanf("%d",&N);
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &z);
        string sz = to_string(z);
        string a = sz.substr(0, sz.size()/2);
        string b = sz.substr(sz.size()/2);
        long long A = stoi(a);
        long long B = stoi(b);
        if(A!=0 && B!=0){
            if(z%A==0){
                if((z/A)%B == 0){
                    printf("Yes\n");
                }
                else printf("No\n");
            }

            else printf("No\n");
        }else printf("No\n");

    }
}