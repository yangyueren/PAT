//
// Created by yryang on 2019/9/10.
//

/*
 * getline(cin, s)的用法，如果前面有回车，一定记得先getchar()
 *
 * cin >> s是遇到空白符号就停止了。
 *
 *
 * */

#include <iostream>
#include "math.h"
#include "vector"
#include "stdio.h"
#include "stdlib.h"
#include "set"
#include "algorithm"
#include "string"
#include "queue"
using namespace std;

struct node{
    int left;
    int right;
    int parent;
};
node tree[15];
int N;
int root;
int countlevel = 0;
int countin = 0;
queue<int> q;
void levelorder(int root){
    if(root < 0) return;
    q.push(root);
    while (q.empty() == false){
        int f = q.front();
        printf("%d", f);
        countlevel++;
        if(countlevel < N) printf(" ");
        q.pop();
        if(tree[f].left != -1) q.push(tree[f].left);
        if(tree[f].right != -1) q.push(tree[f].right);
    }
}
void inorder(int root){
    if(tree[root].left != -1) inorder(tree[root].left);
    printf("%d", root);
    countin++;
    if(countin < N) printf(" ");

    if(tree[root].right != -1) inorder(tree[root].right);
}
int main(){
    scanf("%d", &N);
    getchar();

    int left, right;
    for (int i = 0; i < N; ++i) {
        string s;
        getline(cin, s);
        size_t pos = s.find(" ");
        string leftstr = s.substr(0, pos);
        string rightstr = s.substr(pos+1, s.size()-pos-1);
        if(leftstr == "-") left = -1;
        else {
            left = stoi(leftstr);
            tree[left].parent = i+1;
        }
        if(rightstr == "-") right = -1;
        else {
            right = stoi(rightstr);
            tree[right].parent = i+1;
        }
        tree[i].left = right;
        tree[i].right = left;
        if(tree[i].parent == 0){
            tree[i].parent = -1;
        }

    }
    for (int j = 0; j < N; ++j) {
        if (tree[j].parent == -1){
            root = j;
        } else{
            tree[j].parent -= 1;
        }
    }
    levelorder(root);
    printf("\n");
    inorder(root);
    return 0;
}