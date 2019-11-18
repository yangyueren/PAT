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

struct ndoe{
    char letter;
    int next;
    int isvist;
}nodes[100005];
int N;
int head1, head2;

int main(){
    scanf("%d%d%d",&head1,&head2,&N);
    for (int i = 0; i < N; ++i) {
        int pos, next;
        char val;
        scanf("%d %c %d",&pos,&val,&next);
        nodes[pos].letter = val;
        nodes[pos].next = next;
        nodes[pos].isvist = 0;
    }
    while (head1 != -1){
        nodes[head1].isvist = 1;
        head1 = nodes[head1].next;
    }
    while (head2 != -1){
        if(nodes[head2].isvist == 1){
            break;
        }
        nodes[head2].isvist = 1;
        head2 = nodes[head2].next;
    }
    if(head2 == -1) printf("-1\n");
    else printf("%05d\n", head2);
}