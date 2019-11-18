//
// Created by yryang on 2019/9/15.
//

//重写subway，用dfs。

#include "stdio.h"
#include "stdlib.h"
#include "string"
#include "string.h"
#include "set"
#include "map"
#include "vector"
#include "algorithm"
#include "unordered_map"
#include "iostream"
using namespace std;

const int inf=999999999;
int line[10005][10005];

int source, desti;
int visit[10005];

int trans=0;
int stations=0;
vector<int> path;

int tmpstations = 0;
vector<int> tmppath;


vector<vector<int>> nodes(10005);

int tranferCnt(vector<int> a){
    int cnt=-1, preline=0;
    for (int i = 1; i < a.size(); ++i) {
        if(line[a[i]][a[i-1]] != preline) cnt++;
        preline = line[a[i]][a[i-1]];
    }
    return cnt;
}

void dfs(int index){
    if(index == desti && (tmpstations < stations  || (tmpstations==stations && tranferCnt(tmppath) < trans)) ){
        trans = tranferCnt(tmppath);
        stations = tmpstations;
        path = tmppath;
    } else if(index == desti){
        return;
    } else{
        for (int i = 0; i < nodes[index].size(); ++i) {
            int dd = nodes[index][i];
            if(visit[dd] == 0){

                visit[dd] = 1;
                tmppath.push_back(dd);
                tmpstations++;

                dfs(dd);

                tmppath.pop_back();
                tmpstations--;
                visit[dd] = 0;
            }
        }
    }
}
int main(){
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int j;
        int be, end;
        cin >> j >> be;
        for (int k = 1; k < j; ++k) {
            cin >> end;
            line[be][end] = i;
            line[end][be] = i;
//            printf("%d %d %d\n", be, end, i);
            nodes[be].push_back(end);
            nodes[end].push_back(be);
            be = end;
        }
    }
    int query;
    cin >> query;
    for (int l = 0; l < query; ++l) {
        memset(visit, 0 , sizeof(visit));
        trans = inf;
        stations = inf;
        path.clear();

        tmpstations=0;
        tmppath.clear();

        cin >> source >> desti;
        visit[source] = 1;
        tmppath.push_back(source);

        dfs(source);

        tmppath.pop_back();
        visit[source] = 0;
        cout << path.size()-1 <<endl;
        int preLine = 0, preTransfer = source;
        for (int j = 1; j < path.size(); j++) {
            if (line[path[j-1]][path[j]] != preLine) {
                if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j-1]);
                preLine = line[path[j-1]][path[j]];
                preTransfer = path[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, desti);

//        cout << path.size()-1 << endl;
//        int prest=path[0];
//        int preline;
//        preline = line[path[0]][path[1]];
//        for (int i = 1; i < path.size(); ++i) {
//            if(preline != line[path[i-1]][path[i]]){
//                printf("Take Line#%d from %4d to %4d.\n", preline, prest, path[i-1]);
//                prest = path[i-1];
//                preline = line[path[i-1]][path[i]];
//            }
//
//        }
//        printf("Take Line#%d from %4d to %4d.\n", preline, prest, path[path.size()-1]);

    }

    return 0;
}


//
//int visit[10005];
//int pre[10005];
//int dis[10005];
//int trans[10005];
//int color[10005];
//int MAXS = 10005;
//void dijkstra(int sour, int desti){
//    for (int i = 0; i < MAXS; ++i) {
//        visit[i] = 0;
//        pre[i] = -1;
//        dis[i] = INT32_MAX;
//        trans[i] = INT32_MAX;
//    }
//    dis[sour] = 0;
//    pre[sour] = -1;
//    trans[sour] = 0;
//
//    for (int k = 0; k < MAXS; ++k) {
//        int index=-1;
//        int mindis=INT32_MAX;
//        for (int j = 0; j < MAXS; ++j) {
//            if(dis[j] < mindis && visit[j]==0){
//                index = j;
//                mindis = dis[j];
//            }
//        }
//        visit[index] = 1;
//        if(index==desti){
//            break;
//        }
//        for (int i = 0; i < MAXS; ++i) {
//            if(adj[index][i] > 0 && visit[i] == 0){
//                if(dis[i] > dis[index]+adj[index][i] ){
//                    dis[i] = dis[index]+adj[index][i];
//                    pre[i] = index;
//                    //not transfer station
//                    if(nodes[index].line.size() == 1){
//                        color[i] = color[index];
//                        trans[i] = trans[index];
//                    }
//                        //找到了同颜色的，下一站也是transfer
//                    else if(nodes[index].stationtoline[i] != color[index]){
//                        color[i] = nodes[index].stationtoline[i];
//                        trans[i] = trans[index]+1;
//                    } else{
//                        color[i] = color[index];
//                        trans[i] = trans[index];
//                    }
//                }
//
//                if(dis[i] == dis[index]+adj[index][i] &&  trans[index] < trans[i]){
//                    dis[i] = dis[index]+adj[index][i];
//                    pre[i] = index;
//                    //not transfer station
//                    if(nodes[index].line.size() == 1){
//                        color[i] = color[index];
//                        trans[i] = trans[index];
//                    }
//                        //找到了同颜色的，下一站也是transfer
//                    else if(nodes[index].stationtoline[i] != color[index]){
//                        color[i] = nodes[index].stationtoline[i];
//                        trans[i] = trans[index]+1;
//                    } else{
//                        color[i] = color[index];
//                        trans[i] = trans[index];
//                    }
//                }
//
//            }
//        }
//    }
//
//}
