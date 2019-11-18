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
using namespace std;

int dis[100005];
int main(){
    int N;
    scanf("%d",&N);
    int sum=0;
    for (int i = 2; i <=N+1; ++i) {
        int a;
        scanf("%d",&a);
        sum+=a;
        dis[i] = sum;
    }
    dis[1] = 0;
    int re;
    cin >> re;
    for (int j = 0; j < re; ++j) {
        int b, c;
        cin >> b>>c;
        if(b>c) swap(b,c);
        int left = dis[c] - dis[b];
        int right = sum - left;
        cout << min(left, right)<<endl;
    }
}