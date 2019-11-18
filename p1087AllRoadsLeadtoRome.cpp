//
// Created by yryang on 2019/9/12.
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

int adj[205][205];
int happy[205];

vector<int> pre[205];

int N, K;
map<string, int> mp;
map<int, string> mp2;
int cnt=0;

int visit[205];
int totalhappy[205];
int dis[205];
int dijkstra(){
    memset(visit, 0, sizeof(visit));
    memset(totalhappy, 0, sizeof(totalhappy));
    for (int i = 0; i < N; ++i) {
        visit[i] = 0;
        dis[i] = INT32_MAX;
    }
    int source = 0;
    int end = mp["ROM"];
    int index = -1;
    dis[source] = 0;
    pre[source].push_back(-1);
    for (int j = 0; j < N; ++j) {
        int mindis = INT32_MAX;
        for (int i = 0; i < N; ++i) {
            if(visit[i] == 0 && dis[i] < mindis){
                mindis = dis[i];
                index = i;
            }
        }
        visit[index] = 1;
        if(index == end){
            break;
        }
        for (int k = 0; k < N; ++k) {
            if(visit[k]==0 && adj[index][k] > 0){
                if(dis[k] > dis[index]+adj[index][k]){
                    dis[k] = dis[index] + adj[index][k];
                    pre[k].clear();
                    pre[k].push_back(index);
                }
                else if(dis[k] == dis[index]+adj[index][k]){
                    pre[k].push_back(index);
                }
            }
        }
    }
    return dis[end];
}

int total=0;
double maxavehappy = INT32_MIN;
int maxave = INT32_MIN;
int summax = INT32_MIN;
vector<int> path;
vector<int> minipath;
//当now为0 返回
void dfs(int now){
    if(now == -1){
        total++;
        int th = 0;
        for (int i = 0; i < path.size(); ++i) {
            th += happy[path[i]];
        }
        double av = th*1.0 / (path.size()-1);
        if(av > maxavehappy){
            summax = th;
            maxavehappy = av;
            maxave = floor(maxavehappy);
            minipath.clear();
            for (int i = 0; i < path.size(); ++i) {
                int ddd = path[i];
                minipath.push_back(ddd);
            }
        }
        return;
    }
    path.push_back(now);
    for (int i = 0; i < pre[now].size(); ++i) {
        dfs(pre[now][i]);
    }
    path.pop_back();
}
int main(){
    scanf("%d%d", &N,&K);
    string city;
    cin >> city;
    mp[city] = cnt;
    mp2[cnt] = city;
    happy[mp[city]] = 0;
    cnt++;
    int ha;
    for (int i = 0; i < N - 1; ++i) {
        cin >> city >> ha;
        mp[city] = cnt;
        mp2[cnt] = city;
        happy[mp[city]] = ha;
        cnt++;

    }
    for (int j = 0; j < K; ++j) {
        string be, end;
        int diss;
        cin >> be >> end >> diss;
        adj[mp[be]][mp[end]] = diss;
        adj[mp[end]][mp[be]] = diss;
    }
    int cost = dijkstra();
    int end = mp["ROM"];
    dfs(end);
    cout << total << " " << cost << " "<< summax<< " " << maxave <<endl;
    for (auto k = minipath.rbegin(); k!=minipath.rend(); ++k) {
        if(k!=minipath.rbegin())printf("->");
        cout << mp2[*k];
    }
    cout << endl;
    return 0;
}