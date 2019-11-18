//
// Created by yryang on 2019/9/11.
//

#include "iostream"
#include "string"
#include "stdlib.h"
#include "stdio.h"
#include "map"
#include "vector"
#include "set"
using namespace std;

struct node{
    int val;
    int next;
    bool isremoved;
    node(){

    }
    node(int v){
        val=v;
    }
}nodes[100005];
set<int> absv;
int main(){
    int head, N;
    scanf("%d%d",&head,&N);
    int be, val, end;
    for (int i = 0; i < N; ++i) {
        scanf("%d%d%d", &be,&val,&end);
        nodes[be].val = val;
        nodes[be].next = end;
        if(absv.find(abs(val)) == absv.end()){
            nodes[be].isremoved = false;
            absv.insert(abs(val));
        } else{
            nodes[be].isremoved = true;
        }
    }

    int p = head;
    int removehead=-1;
    while (p!= -1) {
        if(nodes[p].isremoved == true && removehead==-1){
            removehead=p;
        }
        if(nodes[p].isremoved ==false){
            if(p!=head){
                printf("%05d\n", p);
            }
            printf("%05d %d ", p, nodes[p].val);
        }
        p=nodes[p].next;
    }
    if(p==-1 && head != -1){
        printf("-1\n");
    }

    p = removehead;
    while (p!= -1) {
        if(nodes[p].isremoved ==true){
            if(p!=removehead){
                printf("%05d\n", p);
            }
            printf("%05d %d ", p, nodes[p].val);
        }
        p=nodes[p].next;
    }

    if(p==-1 && removehead != -1){
        printf("-1\n");
    }


}