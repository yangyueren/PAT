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

const int mmm=10005;
struct node{
    int par;
    int isin;
}nodes[10005];
int findfa(int x){
    if(x!= nodes[x].par) nodes[x].par = findfa(nodes[x].par);
    return nodes[x].par;
}
int uniony(int x, int y){
    int xr = findfa(x);
    int yr = findfa(y);
    nodes[xr].par = yr;
    return yr;
}
int main(){
    for (int i = 0; i < 10005; ++i) {
        nodes[i].par = i;
        nodes[i].isin = 0;
    }
    int N;
    scanf("%d",&N);
    for (int j = 0; j < N; ++j) {
        int k;
        scanf("%d",&k);
        int head;
        scanf("%d",&head);
        nodes[head].isin = 1;
        for (int i = 1; i < k; ++i) {
            int t;
            scanf("%d", &t);
            nodes[t].isin = 1;
            uniony(t, head);
        }
    }
    int cluster=0;
    int bird=0;
    for (int l = 0; l < mmm; ++l) {
        if(nodes[l].isin==1){
            bird++;
            if(nodes[l].par == l){
                cluster++;
            }
        }
    }
    printf("%d %d\n", cluster, bird);

    int q;
    scanf("%d", &q);
    for (int m = 0; m < q; ++m) {
        int a, b;
        scanf("%d%d",&a,&b);
        if(findfa(a) == findfa(b)){
            printf("Yes\n");
        } else printf("No\n");
    }

    return 0;
}