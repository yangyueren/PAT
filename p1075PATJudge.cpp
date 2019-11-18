//
// Created by yryang on 2019/9/18.
//

#include "stdio.h"
#include "stdlib.h"
#include "vector"
#include "set"
#include "string"
#include "string.h"
#include "map"
#include "algorithm"
#include "iostream"
using namespace std;

struct node{
    int id;
    int totalscore;
    int pro[7];
    int acnum;
    int isshown;
}nodes[100005];

int problemscore[6];

int cmp(node a, node b){
    if(a.totalscore != b.totalscore) return a.totalscore > b.totalscore;
    if(a.acnum != b.acnum) return a.acnum > b.acnum;
    return a.id < b.id;
}
int N,K,M;
int main(){
    cin >> N >> K >> M;
    for (int i = 1; i <= K; ++i) {
        cin >> problemscore[i];
    }
    for (int l = 1; l <= N; ++l) {
        nodes[l].isshown = 0;
        for (int i = 0; i <= K; ++i) {
            nodes[l].pro[i] = -2;
        }
    }
    for (int j = 0; j < M; ++j) {
        int id, proid, sco;
        cin >> id >> proid >> sco;
        nodes[id].id = id;
        if(sco > nodes[id].pro[proid]){
            nodes[id].pro[proid] = sco;
        }
        if(sco > -1){
            nodes[id].isshown = 1;
        }

    }
    for (int k = 1; k <= N; ++k) {
        node a = nodes[k];
        int ts=0;
        int ac=0;
        for (int i = 1; i <= K; ++i) {
            if(a.pro[i] >= 0){
                ts += a.pro[i];
                if(a.pro[i] == problemscore[i]){
                    ac++;
                }
            }
        }
        nodes[k].totalscore = ts;
        nodes[k].acnum = ac;
    }
    sort(nodes+1, nodes+N+1, cmp);
    int ansrank=-1;
    int prescore=-1;
    for (int i = 1; i <= N ; ++i) {
        node a = nodes[i];
        if(a.isshown == 1){
            if(a.totalscore == prescore){
                printf("%d %05d %d", ansrank, a.id, a.totalscore);
                for (int j =1; j <= K ; ++j) {
                    if(a.pro[j] == -1) printf(" 0");
                    if(a.pro[j] == -2) printf(" -");
                    if(a.pro[j] >= 0) printf(" %d", a.pro[j]);
                }
                printf("\n");
                prescore = a.totalscore;

            }  else{
                ansrank = i;
                printf("%d %05d %d", ansrank, a.id, a.totalscore);
                for (int j =1; j <= K ; ++j) {
                    if(a.pro[j] == -1) printf(" 0");
                    if(a.pro[j] == -2) printf(" -");
                    if(a.pro[j] >= 0) printf(" %d", a.pro[j]);
                }
                printf("\n");
                prescore = a.totalscore;

            }
        }
    }
    return 0;
}