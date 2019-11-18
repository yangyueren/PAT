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
    int childnums;
    int child[105];
}nodes[105];
int N;
int M;

queue<int> q;
int level=0;
int maxnum=-1;
int maxlevel=0;
void level_order(int root){
    int num=0;
    int nextnum=0;
    num=1;
    q.push(root);
    while (q.empty()==false){
        level++;
        nextnum=0;
        if(num > maxnum){
            maxnum = num;
            maxlevel=level;
        }
        for (int i = 0; i < num; ++i) {
            int no = q.front();
            q.pop();
            int childnum = nodes[no].childnums;
            nextnum += childnum;
            for (int j = 0; j < childnum; ++j) {
                q.push(nodes[no].child[j]);
            }
        }
        num = nextnum;
    }

}

int main(){
    scanf("%d%d", &N, &M);
    int nownode, num;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &nownode, &num);
        nodes[nownode].childnums = num;
        for (int j = 0; j < num; ++j) {
            scanf("%d", &(nodes[nownode].child[j]));
        }
    }
    level_order(1);
    cout << maxnum << " "<<maxlevel<<endl;
    return 0;
}