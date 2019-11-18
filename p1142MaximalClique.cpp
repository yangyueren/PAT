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

int adj[205][205];
int N;
vector<int> svr;

int judge(){
    int es=0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <=N ; ++j) {
            if( (find(svr.begin(), svr.end(), i) != svr.end()) && (find(svr.begin(), svr.end(), j) != svr.end()) ){
                if(adj[i][j]!=0) es++;
            }
        }
    }
    int rees= svr.size()*(svr.size()-1);

    if (es != rees) return 0;

    int flag = 2;
    for (int i = 1; i <= N; ++i) {
        if( find(svr.begin(), svr.end(), i) == svr.end()){
            auto it = svr.begin();
            for (it = svr.begin();  it!= svr.end() ; it++) {
                if(adj[i][*it] == 0){
                    break;
                }
            }
            if(it == svr.end()) {
                flag = 1;
                break;
            }
        }
    }
    return flag;
}
int main(){
    int M;
    scanf("%d%d",&N,&M);
    for (int i = 0; i < M; ++i) {
        int be, end;
        scanf("%d%d", &be,&end);
        adj[be][end]=1;
        adj[end][be]=1;
    }
    int K;
    scanf("%d",&K);
    for (int j = 0; j < K; ++j) {
        svr.clear();
        int aa;
        int bb;
        scanf("%d", &bb);
        for (int i = 0; i < bb; ++i) {
            scanf("%d",&aa);
            svr.push_back(aa);
        }
        int mre = judge();
        if(mre==0){
            printf("Not a Clique\n");
        }else if(mre == 1){
            printf("Not Maximal\n");
        } else{
            printf("Yes\n");
        }

    }

    return 0;
}