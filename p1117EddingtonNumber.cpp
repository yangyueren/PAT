//
// Created by yryang on 2019/9/14.
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

int N;
int dis[100005];

int binarysearch(int l, int r, int tar){
    if(l<r){
        while(l<r){
            int mid = l+(r-l)/2;
            if(tar >= dis[mid]){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
    }
    return l;
}
int main(){
    scanf("%d",&N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &dis[i]);
    }
    sort(dis, dis+N, greater<int>());

    int maxe=0;
    while(maxe<=N && dis[maxe] > maxe+1) maxe++;
    cout << maxe<<endl;
    return 0;
}