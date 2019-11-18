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
    int letf;
    int right;
    int par;
    string val;

}nodes[25];




int N;
int realroot;
void inorder(int root){
    if(root != -1){
        if(nodes[root].letf != -1 && root != realroot) printf("(");
        if(nodes[root].letf == -1 && root != realroot && nodes[root].right != -1) printf("(");
        inorder(nodes[root].letf);
        cout << nodes[root].val;

        inorder(nodes[root].right);
        if(nodes[root].right != -1 && root != realroot) printf(")");
    } else{
        return;
    }
}
int main(){
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        string val;
        int l, r;
        cin >> val >> l >> r;
        nodes[i].val = val;
        nodes[i].letf = l;
        nodes[i].right = r;
        if(l!=-1) nodes[l].par = i;
        if(r!=-1) nodes[r].par = i;
    }
    int root=1;
    while (nodes[root].par != 0){
        root = nodes[root].par;
    }
    realroot = root;
    inorder(root);

    return 0;
}