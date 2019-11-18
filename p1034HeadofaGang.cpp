//
// Created by yryang on 2019/9/13.
//

//要考虑now自己，考虑节点个数2010个，考虑最后输出要排序
// 并查集只用做判断是否在一个cluster，不要妄想存totalweight

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
    int parent;
    int totalw;
}nodes[2010];

int adj[2010][2010];
int weight[2010];

int K;
int cnt=1;
map<string, int> mp;
map<int, string> mp2;
vector<int> gang;



int finduu(int x){
    int r = x;
    while(r != nodes[r].parent){
        r = nodes[r].parent;
    }
    int k = x;
    while (k != r){
        x = nodes[k].parent;
        nodes[k].parent = r;
        k=x;
    }
    return r;
}
void unionuu(int x, int y, int w){
    int a = finduu(x);
    int b = finduu(y);
    nodes[a].parent = b;
}

//int head=-1;
//int totalw=0;
//void dfs(int index){
//    for (int i = 1; i <= cnt ; ++i) {
//        if(adj[index][i] > 0){
//            totalw += adj[index][i];
//            dfs(i);
//        }
//    }
//}
void findgang(){
    int pa[2010];
    memset(pa, 0, sizeof(pa));
    for (int i = 1; i <= cnt; ++i) {
        int p = finduu(i);
        pa[p]++;
    }
    for (int j = 1; j <=cnt; ++j) {
        if(pa[j] >2){
            int head=j;
            int totalw=0;
            for (int i = 1; i <= cnt ; ++i) {
                if(finduu(j) == finduu(i)){
                    totalw += weight[i];
                    if (weight[i]>weight[head]){
                        head=i;
                    }
                }
            }
            if(totalw > 2*K)
                gang.push_back(head);
        }
    }
}

int findme(int now){
    int t=0;
    for (int i = 1; i <= cnt; ++i) {
        if(adj[now][i] != 0) t++;
    }
    return t+1;
}
int main(){
    int N;
    for (int j = 0; j < 2010; ++j) {
        nodes[j].parent = j;
        nodes[j].totalw = 0;
    }
    scanf("%d%d", &N,&K);
    for (int i = 0; i < N; ++i) {
        string name1, name2;
        int w;
        cin >> name1 >> name2 >> w;
        if(mp[name1]==0){
            mp[name1] = cnt;
            mp2[cnt] = name1;
            cnt++;
        }
        if(mp[name2]==0){
            mp[name2] = cnt;
            mp2[cnt] = name2;
            cnt++;
        }
        int be = mp[name1];
        int end = mp[name2];
        adj[be][end] += w;
        adj[end][be] += w;
        weight[be] += w;
        weight[end] += w;
        unionuu(be, end, w);
    }
    cnt--;//人数
    findgang();
    cout << gang.size()<<endl;

    vector<string> rrr;
    for (auto it = gang.begin(); it!=gang.end() ; it++) {
        rrr.push_back(mp2[*it]);
    }
    sort(rrr.begin(), rrr.end());
    for (auto it = rrr.begin(); it!=rrr.end(); it++) {
        cout << *it << " "<< findme(mp[*it])<<endl;
    }

    return 0;
}