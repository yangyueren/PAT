//
// Created by yryang on 2019/9/12.
//


//第一次会破坏indegree 影响第二次使用，所以需要记录
//如果一次性找出indegree==0的点，然后判断是否在其中，有可能在找到这个点，更新孩子节点的indgree之后，也会将孩子添加进来
//flag=true， 如果没有孩子，根本不会进行的！

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


struct node{
    int indegree;
    vector<int> child;
}nodes[1005];
int degree[1005];
int N;
int input[1005];
vector<int> result;
int tag=0;
void topsort(){
    vector<int> rootnode;
    for (int i = 0; i < N; ++i) {
        int flag=false;
        for (int j = 1; j <= N ; ++j) {
            if(j ==  input[i] && nodes[j].indegree==0){
                flag=true;//没有孩子怎么办
                for (int k = 0; k < nodes[j].child.size(); ++k) {
                    int chi = nodes[j].child[k];
                    nodes[chi].indegree--;
                }
                break;
            }
        }
        if(flag== false) {
            result.push_back(tag);
            break;
        }
    }

}
int main(){
    int M;
    scanf("%d%d", &N, &M);
    int be, end;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d",&be,&end);
        nodes[be].child.push_back(end);
        nodes[end].indegree++;
    }
    for (int l = 1; l <=N ; ++l) {
        degree[l] = nodes[l].indegree;
    }
    int K;
    scanf("%d", &K);
    for (int j = 0; j < K; ++j) {
        for (int l = 1; l <=N ; ++l) {
            nodes[l].indegree = degree[l] ;
        }
        for (int i = 0; i < N; ++i) {
            scanf("%d", &input[i]);
        }

        topsort();
        tag++;
    }
    for (int k = 0; k < result.size(); ++k) {
        if(k!=0) printf(" ");
        printf("%d", result[k]);

    }

    return 0;
}