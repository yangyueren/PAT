//
// Created by yryang on 2019/9/14.
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
    int length;
    int time;
};
node adj[505][505];
int N,M;
int source, desti;

int visit[505];
int ddis[505];
int pre[505];
int dtime[505];
void djkstra(){
    for (int i = 0; i < N; ++i) {
        ddis[i] = INT32_MAX;
        visit[i] = 0;
        dtime[i] = INT32_MAX;
    }
    ddis[source] = 0;
    pre[source] = -1;

    for (int k = 0; k < N; ++k) {
        int index=-1;
        int mindis=INT32_MAX;
        for (int j = 0; j < N; ++j) {
            if(ddis[j] < mindis && visit[j] == 0){
                index = j;
                mindis = ddis[j];
            }
        }
        visit[index] = 1;
        if(index == desti){
            break;
        }
        for (int i = 0; i < N; ++i) {
            if(adj[index][i].length > 0){
                if(adj[index][i].length + ddis[index] < ddis[i]){
                    ddis[i] = adj[index][i].length + ddis[index];
                    dtime[i] = adj[index][i].time + dtime[index];
                    pre[i] = index;
                }
                if(adj[index][i].length + ddis[index] == ddis[i]){
                    if(adj[index][i].time + dtime[index] < dtime[i]){
                        ddis[i] = adj[index][i].length + ddis[index];
                        dtime[i] = adj[index][i].time + dtime[index];
                        pre[i] = index;
                    }
                }
            }
        }
    }

}

void djk2(){
    for (int i = 0; i < N; ++i) {
        ddis[i] = INT32_MAX;
        visit[i] = 0;
        dtime[i] = INT32_MAX;
    }
    dtime[source] = 0;
    ddis[source] = 1;
    pre[source] = -1;

    for (int k = 0; k < N; ++k) {
        int index=-1;
        int mintime=INT32_MAX;
        for (int j = 0; j < N; ++j) {
            if(dtime[j] < mintime && visit[j] == 0){
                index = j;
                mintime = dtime[j];
            }
        }
        visit[index] = 1;
        if(index == desti){
            break;
        }
        for (int i = 0; i < N; ++i) {
            if(adj[index][i].length > 0){
                if(adj[index][i].time + dtime[index] < dtime[i]){
                    ddis[i] = 1 + ddis[index];
                    dtime[i] = adj[index][i].time + dtime[index];
                    pre[i] = index;
                }
                if(adj[index][i].time + dtime[index] == dtime[i]){
                    if(ddis[index] + 1 < ddis[i]){
                        ddis[i] = 1 + ddis[index];
                        dtime[i] = adj[index][i].time + dtime[index];
                        pre[i] = index;
                    }
                }
            }
        }
    }

}
int main(){
    scanf("%d%d",&N,&M);
    for (int i = 0; i < M; ++i) {
        int be, end, oneway, len, time;
        scanf("%d%d%d%d%d",&be,&end,&oneway,&len,&time);
        if(oneway==1){
            adj[be][end].length = len;
            adj[be][end].time = time;
        } else{
            adj[be][end].length = len;
            adj[be][end].time = time;
            adj[end][be].length = len;
            adj[end][be].time = time;
        }
    }
    scanf("%d%d",&source,&desti);
    djkstra();
    int anstotaldis=0;
    anstotaldis = ddis[desti];
    vector<int> ansdis;
    int p = desti;
    while (p != -1){
        ansdis.insert(ansdis.begin(), p);
        p = pre[p];
    }
    djk2();
    int anstotaltime=0;
    anstotaltime = dtime[desti];
    vector<int> anstime;
    p = desti;
    while (p != -1){
        anstime.insert(anstime.begin(), p);
        p = pre[p];
    }
    int flag=1;
    if(ansdis.size() != anstime.size()){
        flag = 0;
    }
    else{
        for (int i = 0; i < ansdis.size(); ++i) {
            if(ansdis[i] != anstime[i]){
                flag = 0;
                break;
            }
        }
    }
    if(flag == 1){
        printf("Distance = %d; Time = %d: ", anstotaldis, anstotaltime);
        for (int i = 0; i < ansdis.size(); ++i) {
            if(i!=0) printf(" -> ");
            printf("%d", ansdis[i]);
        }
        printf("\n");
    } else{
        printf("Distance = %d: ", anstotaldis);
        for (int i = 0; i < ansdis.size(); ++i) {
            if(i!=0) printf(" -> ");
            printf("%d", ansdis[i]);
        }
        printf("\n");
        printf("Time = %d: ", anstotaltime);
        for (int i = 0; i < anstime.size(); ++i) {
            if(i!=0) printf(" -> ");
            printf("%d", anstime[i]);
        }
        printf("\n");
    }
    return 0;
}