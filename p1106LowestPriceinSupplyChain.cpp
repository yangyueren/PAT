//
// Created by yryang on 2019/9/11.
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

struct node{
    int childnum;
    vector<int> child;
    int depth;
}nodes[100005];
int N;
double P,r;

int mindepth=INT32_MAX;
int mindepnum=0;

void dfs(int root, int depth){
    nodes[root].depth = depth;
    if(nodes[root].childnum == 0){
        if(nodes[root].depth < mindepth){
            mindepth = nodes[root].depth;
            mindepnum = 1;
        }else if(nodes[root].depth == mindepth){
            mindepnum++;
        }else{
            return;
        }
    }
    for (int i = 0; i < nodes[root].childnum; ++i) {
        dfs(nodes[root].child[i], depth+1);
    }

}


int main(){
    scanf("%d%lf%lf",&N, &P, &r);
    int childnum, child;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &childnum);
        nodes[i].childnum = childnum;
        nodes[i].depth = -1;
        for (int j = 0; j < childnum; ++j) {
            scanf("%d", &child);
            nodes[i].child.push_back(child);
        }
    }
    dfs(0, 0);
    double re = P*pow((1+r/100.0), mindepth);
    printf("%.4lf %d\n", re+0.00005, mindepnum);
//    cout << re << " "<< mindepnum;
    return 0;
}