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

vector<int> num;
vector<int> read;
int main(){
    int a, N;
    scanf("%d%d",&a,&N);
    num.push_back(a);
    for (int i = 1; i < N; ++i) {
        read.clear();
        int pre;
        int cnt=0;
        for (int j = 0; j < num.size(); ++j) {
            if(j>0) {
                pre=num[j-1];
                if(num[j]!= pre) {
                    read.push_back(pre);
                    read.push_back(cnt);
                    cnt=1;
                }
                if(num[j]==pre){
                    cnt++;
                }
            }
            else {
                pre = num[0];
                cnt=1;
            }
        }

        read.push_back(*num.rbegin());
        read.push_back(cnt);
        num.clear();
        num.insert(num.end(), read.begin(), read.end());
    }
    for (int k = 0; k < read.size(); ++k) {

        cout << read[k];
    }

}