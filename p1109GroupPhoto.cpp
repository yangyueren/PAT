//
// Created by yryang on 2019/9/14.
//

//忘记了flag=0 flag=1要交替进行

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
    string name;
    int height;
}nodes[10005];

vector<string> row[12];

int N, K, m, lastm;

int cmp(node a, node b){
    if(a.height != b.height) return a.height > b.height;
    else return a.name < b.name;
}
int main(){
    cin >> N >> K;
    m = N/K;
    lastm = N/K + N%K;
    for (int i = 0; i < N; ++i) {
        string name;
        int hei;
        cin >> name >> hei;
        nodes[i].name = name;
        nodes[i].height = hei;
    }
    sort(nodes, nodes+N, cmp);
    for (int j = K-1; j>=0 ; --j) {
        if(j==K-1) {
            m = lastm;
            int mid = m/2+1;
            row[j].push_back(nodes[0].name);
            for (int i = 1; i < m; ++i) {
                if(i%2==1) row[j].insert(row[j].begin(), nodes[i].name);
                else row[j].insert(row[j].end(), nodes[i].name);
            }
        }
        else {
            m = N/K;
            int mid = m/2+1;
            int begin = (K-1-j)*m + N%K;
            row[j].push_back(nodes[begin].name);
            int flag=1;
            for (int i = 1; i < m; ++i) {
                if(flag%2==1) {
                    row[j].insert(row[j].begin(), nodes[begin+i].name);
                    flag = 0;
                }
                else {
                    row[j].insert(row[j].end(), nodes[begin+i].name);
                    flag = 1;
                }
            }
        }
    }
    for (int k = K-1; k >=0; --k) {
        for (int i = 0; i < row[k].size(); ++i) {
            if(i!=0) printf(" ");
            cout << row[k][i];
        }
        cout << endl;
    }
    return 0;
}