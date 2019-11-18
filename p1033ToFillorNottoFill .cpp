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
    int dis;
    double pri;
}nodes[505];
int capacity, totaldis, num;
double unit;
double licheng;

double p=0;

int jiaman=0;
int findmin(int now){
    int minindex=-1;
    double npri = INT32_MAX;
    for (int i = now+1; (nodes[i].dis-nodes[now].dis) <= unit*capacity; ++i) {
        if(nodes[i].pri < npri){
            npri = nodes[i].pri;
            minindex = i;
        }
        if(nodes[i].pri < nodes[now].pri) break;
    }
    if(nodes[minindex].pri <= nodes[now].pri){
        jiaman = 0;
    } else jiaman=1;
    return minindex;
}
double greedy(int now, double leftoil){
    if(now == num){

        return 1;
    }
    jiaman=0;
    int next = findmin(now);
    if(jiaman == 1){
        p += (capacity-leftoil)*nodes[now].pri;
        leftoil = capacity - (nodes[next].dis-nodes[now].dis)*1.0/unit;
        greedy(next, leftoil);
    } else{
        p += ((nodes[next].dis-nodes[now].dis)*1.0/unit - leftoil) * nodes[now].pri;
        greedy(next, 0);
    }
    return 0;
}
int cmp(node a, node b){
    return a.dis < b.dis;
}
int main(){
    scanf("%d%d%lf%d",&capacity,&totaldis,&unit,&num);
    licheng = unit*capacity;
    for (int i = 0; i < num; ++i) {
        double pri;
        int dis;
        scanf("%lf%d", &pri,&dis);
        nodes[i].pri = pri;
        nodes[i].dis = dis;
    }
    nodes[num].pri=0;
    nodes[num].dis=totaldis;
    sort(nodes, nodes+num, cmp);
    int flag=-1;
    for (int j = 1; j <= num; ++j) {
        if((nodes[j].dis-nodes[j-1].dis) > capacity*unit){
            flag=j-1;
            break;
        }
    }
    if(nodes[0].dis != 0){
        printf("The maximum travel distance = %.2lf\n", 0.0);
    }
    else if(flag!=-1){
        double umd = nodes[flag].dis + capacity*unit;
        printf("The maximum travel distance = %.2lf\n", umd);
    } else{
        greedy(0, 0);
        printf("%.2lf", p);
    }

}