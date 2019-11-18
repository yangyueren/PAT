//
// Created by yryang on 2019/9/16.
//

#include "iostream"
#include "string"
#include "set"
#include "map"
#include "vector"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "algorithm"
#include "math.h"
using namespace std;

int N;
int num[10005];
int cmp(int a, int b){
    return a > b;
}
int cut[10005];
int main(){
    cin >> N;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &num[i]);
    }
    sort(num, num+N, cmp);
    for (int j = 0; j < N; ++j) {
        cut[j] = j+1;
    }
    cut[N-1] = N-1;
    double sum=0;
    for (int k = 0; k < N; ++k) {
        sum += (num[k]*1.0 / pow(2, cut[k]));
    }
    int result=-1;
    result = floor(sum);
    cout << result << endl;
    return 0;
}