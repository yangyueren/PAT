//
// Created by yryang on 2019/9/13.
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
#include "unordered_map"
using namespace std;


int maxnum[4];
int minnum[4];
int large;
int small;
void tonum(int n){
    for (int i = 0; i < 4; ++i) {
        minnum[i] = n%10;
        n/=10;
    }
    sort(minnum, minnum+4);
    for (int j = 0; j < 4; ++j) {
        maxnum[j] = minnum[3-j];
    }
    large=0;
    small = 0;
    for (int k = 0; k < 4; ++k) {
        large = large*10 + maxnum[k];
        small = small*10 + minnum[k];
    }
}
int main(){
    int n;
    cin >> n;
    tonum(n);
    if(large - small == 0){
        printf("%04d - %04d = %04d\n", large, small, large-small);
    } else{
        while (large - small != 6174){
            printf("%04d - %04d = %04d\n", large, small, large-small);
            tonum(large-small);
        }
        printf("%04d - %04d = %04d\n", large, small, large-small);
    }
}