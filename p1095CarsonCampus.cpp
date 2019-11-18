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
    char name[10];
    int in;
    int out;
}nodes[10005];

int N,M;
int main(){
    for (int i = 0; i < 10005; ++i) {
        nodes[i].in=-1;
        nodes[i].out=-1;
    }
    scanf("%d%d", &N,&M);
    int hh, mm, ss;
}