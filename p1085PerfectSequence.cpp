//
// Created by yryang on 2019/9/12.
//

//***** 超级重要的题目
//binarysearch 的写法
//  注意 if(num[i] > min*P) break;  min*P可能超过int长度，没办法比较，所以要用long long

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

long long N, P;
long long num[100005];

int binarysearch(int l, int r, long long tar){

    while (l<r){
        int mid = l + (r-l)/2+1;
        if(num[mid] > tar){
            r = mid-1;
        }else{
            l=mid;
        }
    }
    return l;
}
int main(){
    scanf("%d%d", &N,&P);
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &num[i]);
    }
    sort(num, num+N);
    int len=-1;
    for (int j = 0; j < N; ++j) {
        long long min = num[j];
        int maxi;
        for (int i = j; i < N; ++i) {
            maxi = binarysearch(j, i , min*P);
        }
        if(maxi-j+1 > len) len = maxi-j+1;
    }
    cout << len;
}
//
//int N, P;
//int num[100005];
//bool isin[100005];
//int maxlen = 0;
//
//int findmaxindex(){
//    int max = INT32_MIN;
//    int index = -1;
//    for (int i = 0; i < N; ++i) {
//        if(num[i] > max && isin[i] == true){
//            index = i;
//            max = num[i];
//        }
//    }
//    return index;
//}
//int findminindex(){
//    int min = INT32_MAX;
//    int index = -1;
//    for (int i = 0; i < N; ++i) {
//        if(num[i] < min && isin[i] == true){
//            index = i;
//            min = num[i];
//        }
//    }
//    return index;
//}
//int findlen(){
//    int cnt=0;
//    for (int i = 0; i < N; ++i) {
//        if(isin[i] == true) cnt++;
//    }
//    return cnt;
//}
//void dfs(int now){
//    if(now == N) {
//        int ax = findmaxindex();
//        int ix = findminindex();
//        if(ax<0||ix<0) return;
//        if((num[ax]*1.0) / num[ix] <= P){
//            int len = findlen();
//            if(len > maxlen) maxlen = len;
//        }
//        return;
//    }
//
//    isin[now] = true;
//    dfs(now+1);
//    isin[now] = false;
//    dfs(now+1);
//
//}
//int main(){
//
//    scanf("%d%d",&N,&P);
//    for (int i = 0; i < N; ++i) {
//        scanf("%d", &num[i]);
//        isin[i] = false;
//    }
//    dfs(0);
//    cout << maxlen;
//}