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
using namespace std;

struct node{
    int add;
    int val;
    int next;
}nodes[100005];

int inihead;
int N;
int K;

vector<node> result;

int main(){
    cin >> inihead >> N >> K;
    for (int i = 0; i < N; ++i) {
        int add;
        int key;
        int next;
        cin >> add >> key >> next;
        nodes[add].val = key;
        nodes[add].next = next;
        nodes[add].add = add;
    }
    int head = inihead;
    while (head != -1){
        result.push_back(nodes[head]);
        head = nodes[head].next;
    }
    N = result.size();
    for (int i = 0; i < N/K; ++i) {
        reverse(result.begin()+i*K, result.begin()+i*K+K);
    }
    for (int i = 0; i < result.size() - 1; ++i) {
        node a = result[i];
        node b = result[i+1];
        printf("%05d %d %05d\n", a.add, a.val, b.add);
    }
    printf("%05d %d -1\n", result[N-1].add, result[N-1].val);



    return 0;
}