//
// Created by yryang on 2019/9/12.
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
using namespace std;

int heap[1005];
int pos[1005];
int cnt=0;
int N;
bool ismax=true;
bool ismin=true;


void postorder(int root){

    if(2*root+1<N) postorder(2*root+1);
    if(2*root+2<N) postorder(2*root+2);
    pos[cnt++] = heap[root];

}

void judge(int root){
    int left, right;
    left = 2*root+1;
    right = 2*root+2;
    if(left<N){
        if (heap[root] < heap[left]) ismax=false;
        if (heap[root] > heap[left]) ismin=false;
        judge(left);
    }
    if(right<N){
        if (heap[root] < heap[right]) ismax=false;
        if (heap[root] > heap[right]) ismin=false;
        judge(right);
    }

}
int main(){
    int M;
    scanf("%d%d",&M,&N);
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &heap[j]);
        }
        ismax=true;
        ismin=true;
        cnt=0;
        judge(0);
        if(ismax) printf("Max Heap\n");
        if(ismin) printf("Min Heap\n");
        if(!ismax && !ismin) printf("Not Heap\n");
        postorder(0);
        for (int k = 0; k < N; ++k) {
            if(k!=0) printf(" ");
            printf("%d", pos[k]);
        }
        printf("\n");
    }
}