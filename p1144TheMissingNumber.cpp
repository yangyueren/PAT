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
using namespace std;

int num[100005];
int N;
int main(){
    scanf("%d", &N);
    int tmp;
    int posnum=0;
    set<int> st;
    for (int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        if(tmp>0){
            if(st.find(tmp) == st.end()){
                st.insert(tmp);
                posnum++;
            }

        }
    }

    int tag=1;
    for (auto j = st.begin(); j != st.end(); ++j) {
        if(*j!=tag){
            break;
        }
        tag++;
    }
    printf("%d\n", tag);
    return 0;
}