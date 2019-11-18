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

struct node{
    vector<int> child;
    int depth;
}nodes[100005];
int N;
double P,r;

int maxdepth=INT32_MIN;
int maxnum=0;

void dfs(int root, int depth){
    nodes[root].depth = depth;
    if(nodes[root].child.size() == 0){
        if(nodes[root].depth > maxdepth){
            maxdepth = nodes[root].depth;
            maxnum=1;
        }else if(nodes[root].depth == maxdepth){
            maxnum++;
        }else{
            return;
        }
    }
    for (int i = 0; i < nodes[root].child.size(); ++i) {
        dfs(nodes[root].child[i], depth+1);
    }

}


int main(){
    scanf("%d%lf%lf",&N, &P, &r);
    int upper;
    int root;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &upper);
        if(upper==-1) root = i;
        else nodes[upper].child.push_back(i);
    }
    dfs(root, 0);
    double re = P*pow((1+r/100.0), maxdepth);
    printf("%.2lf %d\n", re, maxnum);
//    cout << re << " "<< mindepnum;
    return 0;
}