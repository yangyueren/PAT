//
// Created by yryang on 2019/9/15.
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
#include "unordered_map"
using namespace std;

const int inf = 999999999;
int N,M,K,Ds;
int totalnode;
int dis[1150][1150];
int ansid = -1;
double anslen=0, ansminlen=-1;
int path[1150];
int visit[1150];
int main(){
    cin >> N >> M >> K >> Ds;
    totalnode = N+M;
    for (int j = 0; j <= totalnode; ++j) {
        for (int i = 0; i <= totalnode; ++i) {
            dis[j][i] = inf;
            if(i==j) dis[i][j] = 0;
        }
    }

    for (int i = 0; i < K; ++i) {
        string sbe, send;
        int di;
        cin >> sbe >> send >> di;
        int be, end;
        if(sbe[0] == 'G'){
            be = N + stoi(sbe.substr(1));
        } else{
            be = stoi(sbe);
        }
        if(send[0] == 'G'){
            end = N + stoi(send.substr(1));
        } else{
            end = stoi(send);
        }

        dis[be][end] = di;
        dis[end][be] = di;

    }
    ansid = -1;
    ansminlen = -1;
    anslen = inf;
    for (int index = N+1;index<= totalnode ; ++index) {

        for (int i = 0; i < 1150; ++i) {
            visit[i] = 0;
            path[i] = inf;
        }
        path[index] = 0;
        for (int j = 1; j <= totalnode ; ++j) {
            int minind=-1;
            int mindis = inf;
            for (int i = 1; i <= totalnode ; ++i) {
                if(visit[i]==0 && path[i] < mindis){
                    mindis = path[i];
                    minind = i;
                }
            }
            if(minind == -1){
                break;
            }
            visit[minind] = 1;
            for (int k = 1; k <= totalnode ; ++k) {
                if(visit[k]==0 && path[minind] + dis[minind][k] < path[k]){
                    path[k] = path[minind] + dis[minind][k];
                }
            }
        }

        double tmin=inf;
        double sum=0;
        int flag=1;
        for (int l = 1; l <= N ; ++l) {
            if(path[l] > Ds){
                flag=0;
                break;
            }
            sum += path[l];
            if(path[l] < tmin) tmin=path[l];
        }
        sum = sum;
        if(flag && ansminlen < tmin){
            ansid = index;
            anslen = sum;
            ansminlen = tmin;
        } else if(flag && ansminlen == tmin && anslen > sum){
            ansid = index;
            anslen = sum;
            ansminlen = tmin;
        } else{
            continue;
        }
    }
    if(ansid == -1){
        printf("No Solution\n");
    } else{
        anslen /= N;
        printf("G%d\n%.1lf %.1lf", ansid - N, ansminlen, round(anslen*10)/10.0);
    }

}




//const  int MAXN = 1100;
//int dis[MAXN][MAXN];
//int N,M,K,Ds;
//int totalnode;
//void floyd(){
//    for (int k = 1; k <= totalnode; ++k) {
//        for (int i = 1; i <= totalnode; ++i) {
//            for (int j = 1; j <= totalnode; ++j) {
//                if(dis[i][j] > dis[i][k] + dis[k][j]){
//                    dis[i][j] = dis[i][k] + dis[k][j];
//                }
//            }
//        }
//    }
//    return;
//}
//int main(){
//
//    cin >> N >> M >> K >> Ds;
//    totalnode = N+M;
//    for (int j = 0; j <= totalnode; ++j) {
//        for (int i = 0; i <= totalnode; ++i) {
//            dis[j][i] = inf;
//            if(i==j) dis[i][j] = 0;
//        }
//    }
//
//    for (int i = 0; i < K; ++i) {
//        string sbe, send;
//        int di;
//        cin >> sbe >> send >> di;
//        int be, end;
//        if(sbe[0] == 'G'){
//            be = N + stoi(sbe.substr(1));
//        } else{
//            be = stoi(sbe);
//        }
//        if(send[0] == 'G'){
//            end = N + stoi(send.substr(1));
//        } else{
//            end = stoi(send);
//        }
//        if(di < dis[be][end]){
//            dis[be][end] = di;
//            dis[end][be] = di;
//        }
//    }
//    floyd();
//
//    int num[totalnode+1];
//    for (int n = 0; n <= totalnode; ++n) {
//        num[n] = 0;
//    }
//
//    for (int k = N+1; k <= totalnode; ++k) {
//        for (int i = 1; i <= N ; ++i) {
//            if(dis[k][i] > Ds){
//                num[k] = -100;
//                break;
//            }
//            num[k] += dis[k][i];
//        }
//    }
//    int maxdis=-10;
//    int index = -1;
//    for (int l = N+1; l <= totalnode; ++l) {
//        if(num[l] > maxdis){
//            maxdis = num[l];
//        }
//    }
//    vector<int> daiding;
//    for (int i = N+1; i <= totalnode; ++i) {
//        if(num[i] == maxdis) daiding.push_back(i);
//    }
//
//    //station 最小
//    for (int n = 0; n <= totalnode; ++n) {
//        num[n] = 0;
//    }
//    for (int i = N+1; i <= totalnode; ++i) {
//        for (int j = N+1; j <= totalnode ; ++j) {
//            num[i] += dis[i][j];
//        }
//    }
//    if(daiding.size() > 0){
//        int minsta = num[daiding[0]];
//        index = daiding[0];
//        for (int i = 0; i < daiding.size(); ++i) {
//            if(num[daiding[i]] < minsta) {
//                minsta = num[daiding[i]];
//                index = daiding[i];
//            }
//        }
//        cout << "G"<< index-N <<endl;
//        int min=INT32_MAX;
//        double sum=0;
//        for (int m = 1; m <= N ; ++m) {
//            sum+=dis[index][m];
//            if(dis[index][m] < min) min = dis[index][m];
//        }
//        printf("%.1lf %.1lf\n", min*1.0, round(sum/N*10) / 10);
//
//    }else{
//        printf("No Solution\n");
//    }
//
//    return 0;
//}

//
//totalnode = 9;
//for (int j = 0; j <= totalnode; ++j) {
//for (int i = 0; i <= totalnode; ++i) {
//dis[j][i] = 100000;
//if(i==j) dis[i][j] = 0;
//}
//}
//dis[0][1]=1;
//dis[0][2]=5;
//dis[1][2]=3;
//dis[1][3]=7;
//dis[1][4]=5;
//
//dis[2][4]=1;
//dis[2][5]=7;
//dis[3][4]=2;
//dis[3][6]=3;
//dis[4][5]=3;
//
//dis[4][6]=6;
//dis[4][7]=9;
//dis[5][7]=5;
//dis[6][7]=2;
//dis[6][8]=7;
//
//dis[7][8]=4;
//for (int i = 0; i < totalnode; ++i) {
//for (int j = 0; j < totalnode; ++j) {
//dis[j][i] = dis[i][j];
//}
//}
//
//floyd();