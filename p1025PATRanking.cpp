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
#include "queue"
#include "stack"
using namespace std;

struct node{
    string name;
    int score;
    int loc;
    int locrank;
    int totalrank;
};
vector<node> nodes;
int N;
vector<int> locations;
int totalcnt=0;
int cnt=0;

int cmp(node a, node b){
    if(a.score != b.score) return a.score > b.score;
    else return a.name < b.name;
}
int main(){
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int M;
        cin >> M;
        cnt++;
        locations.push_back(M);
        for (int j = 0; j < M; ++j) {
            string name;
            int score;
            cin >> name >> score;
            node a;
            a.name = name;
            a.score = score;
            a.loc = cnt;
            nodes.push_back(a);
            totalcnt++;
        }
        sort(nodes.begin() + totalcnt-M, nodes.end(), cmp);
        int rank=0;
        int prescore = 101;
        for (int k = totalcnt-M; k < totalcnt; ++k) {
            if(nodes[k].score != prescore){
                nodes[k].locrank = k - (totalcnt-M)+1;
                prescore = nodes[k].score;
                rank = k - (totalcnt-M)+1;
            } else{
                nodes[k].locrank = rank;
            }
        }
    }
    sort(nodes.begin(), nodes.end(), cmp);
    int rank=0;
    int prescore = 101;
    for (int k = 0; k < totalcnt; ++k) {
        if(nodes[k].score != prescore){
            nodes[k].totalrank = k +1;
            prescore = nodes[k].score;
            rank = k +1;
        } else{
            nodes[k].totalrank = rank;
        }
    }

    cout << totalcnt<<endl;
    for (int l = 0; l < totalcnt; ++l) {
        printf("%s %d %d %d\n", nodes[l].name.c_str(), nodes[l].totalrank, nodes[l].loc, nodes[l].locrank);
    }

    return 0;
}