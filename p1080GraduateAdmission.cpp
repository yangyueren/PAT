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

struct node{
    int id;
    int e;
    int m;
    int sum;
    int prefer[7];
};
int school[105];
vector<node> admit[105];
vector<node> stu;
int N,M,K;

int cmp(node a, node b){
    if(a.sum != b.sum) return a.sum>b.sum;
    if(a.e != b.e) return a.e > b.e;
    return a.id < b.id;
}
int cmpid(node a, node b){
    return a.id < b.id;
}
int thesame(node a, node b){
    if(a.m == b.m && a.e == b.e) return 1;
    else return 0;
}
int checkschool(node a, int sch){
    if(school[sch] > admit[sch].size()){
        admit[sch].push_back(a);
        return 1;
    } else{
        node laststu = *admit[sch].rbegin();
        if(thesame(laststu, a)){
            admit[sch].push_back(a);
            return 1;
        } else{
            return 0;
        }
    }

}
int main(){
    scanf("%d%d%d",&N,&M, &K);
    for (int i = 0; i < M; ++i) {
        scanf("%d", &school[i]);
    }
    int e, m, sch;
    for (int j = 0; j < N; ++j) {
        scanf("%d%d",&e,&m);
        node s;
        s.e = e;
        s.m = m;
        s.sum = e+m;
        s.id = j;
        for (int i = 0; i < K; ++i) {
            scanf("%d", &sch);
            s.prefer[i] = sch;
        }
        stu.push_back(s);
    }
    sort(stu.begin(), stu.end(), cmp);
    for (auto it = stu.begin();  it!=stu.end() ; it++) {
        for (int i = 0; i < K; ++i) {
            if (checkschool(*it, it->prefer[i]) != 0){
                break;
            }
        }
    }
    for (int k = 0; k < M; ++k) {
        sort(admit[k].begin(), admit[k].end(), cmpid);
    }
    for (int l = 0; l < M; ++l) {
        for (int i = 0; i < admit[l].size(); ++i) {
            if(i!=0) printf(" ");
            printf("%d", admit[l][i].id);
        }
        printf("\n");
    }

    return 0;
}