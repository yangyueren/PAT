//
// Created by yryang on 2019/9/11.
//

#include "iostream"
#include "string"
#include "stdlib.h"
#include "stdio.h"
#include "map"
#include "vector"
#include "set"
#include "algorithm"
#include "queue"
using namespace std;


struct node{
    int left;
    int right;
    int val;
}nodes[105];

int N;
int num[105];
vector<node*> ino;
queue<int> q;
void inorder(int root){
    if(root == -1) return;
    if(root >=0){
        inorder(nodes[root].left);
        ino.push_back(&nodes[root]);
        inorder(nodes[root].right);
    }
}
void test(int root){
    if(root == -1) return;
    q.push(root);
    while (q.empty()==false){
        int now = q.front();
        if(now!=0) printf(" ");
        printf("%d", nodes[now].val);
        q.pop();
        if(nodes[now].left!=-1) q.push(nodes[now].left);
        if(nodes[now].right!=-1) q.push(nodes[now].right);
    }

}

int main(){
    scanf("%d", &N);
    int left, right;
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &left,&right);
        nodes[i].left = left;
        nodes[i].right = right;
        nodes[i].val = -1;
    }
    for (int j = 0; j < N; ++j) {
        scanf("%d", &num[j]);
    }
    sort(num, num+N);
    inorder(0);
    vector<node*>::iterator itr = ino.begin();
    int i=0;
    while (itr!=ino.end()){
//        cout << (*itr)->left <<" "<<(*itr)->right<<"\n";
        (*itr)->val = num[i];
        i++;
        itr++;
    }
    test(0);
    return 0;
}