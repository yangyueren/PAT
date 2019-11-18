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

struct node{
    string name;
    int id;
    int score;
};
vector<node> nodes;
int choice=0;
int cmp(node a, node b){
    if(choice==1){
        return a.id < b.id;
    } else if(choice==2){
        if(a.name != b.name) return a.name < b.name;
        else return a.id < b.id;
    } else if(choice==3){
        if(a.score != b.score) return a.score < b.score;
        else return a.id < b.id;
    } else{
        return 0;
    }
}
int N;
int main(){
    cin >> N >> choice;
    for (int i = 0; i < N; ++i) {
        node a;
        cin >> a.id >> a.name >> a.score;
        nodes.push_back(a);
    }
    sort(nodes.begin(), nodes.end(), cmp);
    for (int j = 0; j < nodes.size(); ++j) {
        printf("%06d %s %d\n", nodes[j].id, nodes[j].name.c_str(), nodes[j].score);
    }
    return 0;
}