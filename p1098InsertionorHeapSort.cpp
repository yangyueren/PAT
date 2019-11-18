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
using namespace std;

int N;
int ini[105];
int num[105];
//void insertsort(){
//    for (int i = 1; i < N; ++i) {
//        for (int j = i-1; j >=0 ; --j) {
//            if (num[j] > num[j+1]){
//                int tmp = num[j];
//                num[j] = num[j+1];
//                num[j+1] = tmp;
//            }
//        }
//    }
//}


//n is end pos
void fixdown(int k, int n){
    if(k>=n) return;
    int child = 2*k+1;
    while (child <= n){
        if(child+1<=n && num[child] < num[child+1]){
            child = child+1;
        }
        if(num[child] > num[k]){
            int tmp = num[k];
            num[k] =num[child];
            num[child] = tmp;
        }
        k = child;
        child = 2*k+1;
    }
}

int main(){
    scanf("%d",&N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &ini[i]);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &num[i]);
    }
    int insertnum=0;
    int heapnum=0;
    for (int j = 0; j < N-1; ++j) {
        if(num[j] <num[j+1]) insertnum++;
        else break;
    }
    for(int j = N-1; j>0; --j){
        if(num[j] > num[j-1]) heapnum++;
        else break;
    }
    int sameinsert=0;
    int sameheap=0;
    for (int j = 0; j < N-1; ++j) {
        if(num[j] == ini[j]) sameheap++;
        else break;
    }
    for (int j = N-1; j >= 0; --j) {
        if(num[j] == ini[j]) sameinsert++;
        else break;
    }


//cout << insertnum<< " " << heapnum;
    if(insertnum >= heapnum){
        if(insertnum > heapnum || ((insertnum==heapnum) && (sameinsert>sameheap))){
            printf("Insertion Sort\n");
            for (int j = insertnum; j >=0 ; --j) {
                if (num[j] > num[j+1]){
                    int tmp = num[j];
                    num[j] = num[j+1];
                    num[j+1] = tmp;
                }
            }
        }


    }
    if(heapnum >= insertnum){
        if(heapnum > insertnum  || ((insertnum==heapnum) && (sameheap>sameinsert))){
            printf("Heap Sort\n");
            int pos = N - heapnum-1;
            int tmp = num[0];
            num[0] = num[pos];
            num[pos] = tmp;
            fixdown(0, pos-1);
        }

    }
    for (int k = 0; k < N; ++k) {
        if(k!=0) printf(" ");
        printf("%d", num[k]);
    }
    return 0;
}