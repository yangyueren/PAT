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
#include "queue"
using namespace std;

int adj[1005][1005];
int N, L;
int source;
int cnt=-1;
int visit[1005];
void bfs(int index, int level){
    if(level > L) return;
    else{
        queue<int> q;
        q.push(index);
        queue<int> p;
        while (!q.empty()){
            level++;
            if(level <= L){
                while (!q.empty()){
                    int now = q.front();
                    q.pop();
                    for (int i = 1; i <=N ; ++i) {
                        if(adj[now][i] == 1 && visit[i] == 0){
                            p.push(i);
                            visit[i] = 1;
                            cnt++;
                        }
                    }
                }
            }
            q = p;
            while (!p.empty()) p.pop();
        }
    }
}

int main(){
    cin >> N >> L;
    for (int i = 1; i <=N ; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int num;
            cin >> num;
            adj[num][i] = 1;
        }
    }
    int query;
    cin >> query;
    for (int l = 0; l < query; ++l) {
        cin >> source;
        memset(visit, 0 , sizeof(visit));
        visit[source] = 1;
        cnt=0;
        bfs(source, 0);
        cout << cnt << endl;
    }
    return 0;
}