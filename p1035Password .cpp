//
// Created by yryang on 2019/9/13.
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
    char name[20];
    char pass[20];
    int ischanged;
}nodes[1005];
int N;
int cnt=0;
map<char,char> mp;
void cal(int i){
    int len = strlen(nodes[i].pass);
    int flag = 0;
    for (int j = 0; j < len; ++j) {
        if(mp.find(nodes[i].pass[j]) != mp.end()){
            nodes[i].pass[j] = mp[nodes[i].pass[j]];
            nodes[i].ischanged = 1;
            flag = 1;
        }
    }
    if(flag!=0) cnt++;

}
int main(){
    mp['1'] = '@';
    mp['0'] = '%';
    mp['l'] = 'L';
    mp['O'] = 'o';
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s%s",nodes[i].name, nodes[i].pass);
        cal(i);
    }
    if(cnt>0){
        cout << cnt<<endl;
        for (int j = 0; j < N; ++j) {
            if(nodes[j].ischanged == 1){
                cout << nodes[j].name << " "<< nodes[j].pass<<endl;
            }
        }
    } else if(N==1){
        printf("There is 1 account and no account is modified\n");
    } else{
        printf("There are %d accounts and no account is modified\n",N);
    }

    return 0;
}