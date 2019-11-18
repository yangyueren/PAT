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

int maxnum=0;
string maxs;
unordered_map<string,int> mp;
int M,N;
int main(){

    scanf("%d%d",&M, &N);
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            string s;
            cin >> s;
            mp[s]++;
            if(mp[s] > maxnum){
                maxnum = mp[s];
                maxs = s;
            }
        }
    }
    cout << maxs << endl;
}