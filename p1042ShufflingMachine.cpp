//
// Created by yryang on 2019/9/13.
//
//注意分组 13 对应的是第0组，所以13-1 % 13 + 1和 13-1 / 13

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

const int qq = 54;
int num[56];
int pai[56];
void shuffle(){
    int ar[56];

    for (int i = 1; i <= qq ; ++i) {
        ar[num[i]] = pai[i];
    }
    copy(begin(ar), end(ar), pai);
}
int main(){
    int re;
    for (int j = 1; j <= qq; ++j) {
        pai[j] = j;
    }
    scanf("%d", &re);
    for (int i = 1; i <= qq; ++i) {
        scanf("%d", &num[i]);
    }
    for (int k = 0; k < re; ++k) {
        shuffle();
    }
    char cc[5] = {'S','H','C','D','J'};
    for (int l = 1; l <= qq; ++l) {
        if(l!=1) printf(" ");
        pai[l] = pai[l]-1;
        printf("%c", cc[pai[l]/13]);
        printf("%d", pai[l]%13 + 1);
    }

}