//
// Created by yryang on 2019/9/16.
//

#include "iostream"
#include "string"
#include "set"
#include "map"
#include "vector"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "algorithm"
#include "math.h"
using namespace std;

int N, M;
int degree[505];

int cnt=0;
int visit[505];
int adj[505][505];
void dfs(int index){
    visit[index] = 1;
    cnt++;
    if(cnt == N){
        return;
    } else{
        for (int i = 1; i <= N; ++i) {
            if(adj[index][i] != 0 && visit[i] != 1){
                dfs(i);
            }
        }
    }
}

int main(){
    cin >> N >> M;
    memset(degree, 0 , sizeof(degree));
    for (int i = 0; i < M; ++i) {
        int be, end;
        cin >> be >> end;
        degree[be]++;
        degree[end]++;
        adj[be][end] = adj[end][be] = 1;
    }
    int alleven = 1;
    int twoodd = 0;
    for (int j = 1; j <= N; ++j) {
        if(degree[j] % 2 == 1){
            alleven = 0;
            twoodd ++;
        }
    }
    dfs(1);
    if(alleven == 1 && cnt == N){
        for (int i = 1; i <= N; ++i) {
            if(i!=1) printf(" ");
            printf("%d", degree[i]);
        }
        printf("\n");
        printf("Eulerian\n");
    } else if(twoodd == 2 && cnt==N){
        for (int i = 1; i <= N; ++i) {
            if(i!=1) printf(" ");
            printf("%d", degree[i]);
        }
        printf("\n");
        printf("Semi-Eulerian");
    } else{
        for (int i = 1; i <= N; ++i) {
            if(i!=1) printf(" ");
            printf("%d", degree[i]);
        }
        printf("\n");
        printf("Non-Eulerian\n");
    }

    return 0;
}