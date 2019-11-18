//
// Created by yryang on 2019/9/15.
//

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


struct node{
    int indice;
    int times;
};
node item[50005];

node rec[12];


int cmp(node a, node b){
    if(a.times!=b.times) return a.times>b.times;
    else return a.indice < b.indice;
}

int N,M;
int main(){
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        int q;
        cin >> q;
        if(i!=0){
            cout << q << ":";
            for (int j = 0; j < M && j<i; ++j) {
                cout << " " << rec[j].indice;
            }
            cout << endl;
        }
        item[q].indice = q;
        item[q].times++;
        if(item[q].times > rec[M-1].times || (item[q].times == rec[M-1].times && item[q].indice < rec[M-1].indice)){
            int flag=-1;
            for (int j = 0; j < M; ++j) {
                if(rec[j].indice == q) flag=j;
            }
            if(flag!=-1){
                rec[flag].times++;
            } else{
                rec[M-1] = item[q];
            }
            sort(rec, rec+M, cmp);
        }

    }
    return 0;
}