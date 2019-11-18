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

int num[100005];
vector<int> a;
int main(){
    int N;
    scanf("%d",&N);
    for (int i = 0; i < N; ++i) {
        int b;
        scanf("%d", &b);
        a.push_back(b);
        num[b]++;
    }
    int flag = 0;
    for (int j = 0; j < a.size(); ++j) {
        if(num[a[j]] == 1){
            cout << a[j]<<endl;
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        cout << "None\n";
    }
    return 0;
}