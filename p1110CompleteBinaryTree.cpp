//
// Created by yryang on 2019/9/14.
//
// 完全二叉树，一定会填满1-N，所以只需要dfs找到最大index，与N比较即可。

#include <iostream>
using namespace std;
struct node{
    int l, r;
}a[100];
int maxn = -1, ans;
void dfs(int root, int index) {
    if(index > maxn) {
        maxn = index;
        ans = root;
    }
    if(a[root].l != -1) dfs(a[root].l, index * 2);
    if(a[root].r != -1) dfs(a[root].r, index * 2 + 1);
}
int main() {
    int n, root = 0, have[100] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        string l, r;
        cin >> l >> r;
        if (l == "-") {
            a[i].l = -1;
        } else {
            a[i].l = stoi(l);
            have[stoi(l)] = 1;
        }
        if (r == "-") {
            a[i].r = -1;
        } else {
            a[i].r = stoi(r);
            have[stoi(r)] = 1;
        }
    }
    while (have[root] != 0) root++;
    dfs(root, 1);
    if (maxn == n)
        cout << "YES " << ans;
    else
        cout << "NO " << root;
    return 0;
}

//
//#include "iostream"
//#include "string.h"
//#include "string"
//#include "stdlib.h"
//#include "stdio.h"
//#include "map"
//#include "vector"
//#include "set"
//#include "math.h"
//#include "queue"
//#include "algorithm"
//using namespace std;
//
//struct node{
//    int left;
//    int right;
//    int par;
//    int index;
//}nodes[25];
//
//
//void dfs(int root){
//    if(nodes[root].left != -1){
//        int left = nodes[root].left;
//        nodes[left].index = 2*nodes[root].index+1;
//        dfs(left);
//    }
//    if(nodes[root].right != -1){
//        int right = nodes[root].right;
//        nodes[right].index = 2*nodes[root].index+2;
//        dfs(right);
//    }
//    return;
//}
//int N;
//int main(){
//    cin >> N;
//    for (int i = 0; i < N; ++i) {
//        string a, b;
//        int left, right;
//        cin >> a >> b;
//        if(a == "-") left = -1;
//        else left = stoi(a);
//        if(b == "-") right = -1;
//        else right = stoi(b);
//
//        nodes[i].left = left;
//        nodes[i].right = right;
//        nodes[left].par = i+1;
//        nodes[right].par = i+1;
//    }
//    int root;
//    for (int j = 0; j < N; ++j) {
//        if(nodes[j].par == 0) {
//            root = j;
//            nodes[j].par = j;
//
//        } else{
//            nodes[j].par -= 1;
//        }
//    }
//    dfs(root);
//    int exist[25];
//    for (int l = 0; l < 25; ++l) {
//        exist[l] = 1;
//    }
//    for (int k = 0; k < N; ++k) {
//        int index = nodes[k].index;
//        exist[index] = 0;
//    }
//    int flag=1;
//    for (int m = 0; m < N; ++m) {
//        if(exist[m] ==1) flag=0;
//    }
//    if(flag==0){
//        printf("NO %d\n", root);
//    }
//    else{
//        int max=-1;
//        for (int i = 0; i < N; ++i) {
//            if(nodes[i].index == N-1) max=i;
//        }
//        printf("YES %d", max);
//    }
//
//
//
//    return 0;
//}