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
    string sch;
    int score[4];
    int tws;
    int ns;
    int rank;
}nodes[100005];

map<string, int>mp;
map<int, string>mp2;

string lower(string s){
    string a="";
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]>='A'&&s[i]<='Z') a+= (s[i]-'A'+'a');
        else a+=s[i];
    }
    return a;
}

int cnt=0;


int cmp(node a, node b){
    if(a.tws != b.tws) return a.tws>b.tws;
    if(a.ns != b.ns) return a.ns < b.ns;
    return a.sch < b.sch;
}
int main(){
    int N;
    scanf("%d",&N);
    string name, sch;
    int score;
    map<char, int> wei;
    wei['B'] = 0;
    wei['A'] = 1;
    wei['T'] = 2;
    for (int i = 0; i < N; ++i) {
        cin >> name >> score >> sch;
        sch = lower(sch);
        if(mp.find(sch) == mp.end()){
            mp[sch] = cnt;
            mp2[cnt] = sch;
            cnt++;
        }
        int k = mp[sch];
        nodes[k].ns++;
        nodes[k].score[wei[name[0]]] += score;
        nodes[k].sch = sch;
    }
    for (int j = 0; j < cnt; ++j) {
        nodes[j].tws = (nodes[j].score[0]*2.0/3 +nodes[j].score[1]*1 + nodes[j].score[2]*1.5);
    }
    sort(nodes, nodes+cnt, cmp);

    cout << cnt << endl;
    int rank=1;
    for (int l = 0; l < cnt; ++l) {
        node nd = nodes[l];
        if(l>0){
            if(nodes[l].tws == nodes[l-1].tws) rank = rank;
            else rank = l+1;
        }
        printf("%d %s %d %d\n", rank, nd.sch.c_str(), nd.tws, nd.ns);
    }
}