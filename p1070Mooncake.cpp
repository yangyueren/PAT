//
// Created by yryang on 2019/9/15.
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

struct node{
    double ton;
    double totalpri;
    double pri;
}nodes[10005];

double total;
double price=0;
double now=0;
int N;

int cmp(node a, node b){
    return a.pri > b.pri;
}

int main(){

    cin >> N >> total;
    for (int i = 0; i < N; ++i) {
        cin >> nodes[i].ton;
    }
    for (int j = 0; j < N; ++j) {
        cin >> nodes[j].totalpri;
        nodes[j].pri = nodes[j].totalpri / nodes[j].ton;
    }
    sort(nodes, nodes+N, cmp);
    for (int k = 0; k < N; ++k) {
        if(now + nodes[k].ton >= total){
            price += (total-now)*nodes[k].pri;
            break;
        }else{
            price += nodes[k].totalpri;
            now += nodes[k].ton;
        }
    }
    printf("%.2lf\n", price);

    return 0;
}