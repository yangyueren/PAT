//
// Created by yryang on 2019/9/14.
//

// pre   1 2 3 4 5
// post  5 3 4 2 1
// 当root 1 的左节点为2，但是post里面也为2，所以只有一个孩子，就会出现不确定的情况。

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
int pre[35];
int post[35];
int ino[35];
int N;
struct node{
    node* left;
    node* right;
    int val;
};
int flag = 0;
vector<int> result;
node * build(int prel, int prer, int postl, int postr){
    if(prel < prer){
        int val = pre[prel];
        node* root = new node();
        root->val = val;

        int leftroot = 100;
        for (int i = postl; i <= postr; ++i) {
            if(post[i] == pre[prel+1]){
                leftroot = i;
                break;
            }
        }
        if(leftroot == postr-1) flag = 1;
        int leftlen = leftroot - postl+1;
        root->left = build(prel+1, prel+leftlen, postl, leftroot);
        root->right = build(prel+leftlen+1, prer, leftroot+1, postr-1);

        return root;
    }else if(prel == prer){
        node* root = new node();
        root->val = pre[prel];
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else{
        return NULL;
    }

}
void inorder(node * root){
    if(root!=NULL){
        inorder(root->left);
        result.push_back(root->val);
        inorder(root->right);
    }
}
int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &pre[i]);
    }
    for (int j = 0; j < N; ++j) {
        scanf("%d", &post[j]);
    }

    node* root = build(0,N-1, 0, N-1);
    if(flag == 1)printf("No\n");
    else printf("Yes\n");

    inorder(root);
    for (int k = 0; k < result.size(); ++k) {
        if(k!=0) printf(" ");
        printf("%d", result[k]);
    }
    printf("\n");

    return 0;
}
//
//int pre[35];
//int post[35];
//int ino[35];
//int N;
//struct node{
//    node* left;
//    node* right;
//    int val;
//};
//int flag = 0;
//vector<int> result;
//int findcommonlen(int prel,int prer, int postl, int postr){
//    int com[35];
//    for (int j = 0; j < N; ++j) {
//        com[j] = 1;
//    }
//    for (int i = postl; i <= postr; ++i) {
//        com[post[i]] = 0;
//        int pos=-1;
//        for (int j = prel; j <= prer; ++j) {
//            if(com[pre[j]] != 0){
//                break;
//            } else{
//                pos = j;
//            }
//        }
//        if(pos >= prel){
//            return (pos-prel+1);
//        }
//    }
//    return 0;
//}
//node * build(int prel, int prer, int postl, int postr){
//    if(prel <= prer){
//        int val = pre[prel];
//        int comlen = findcommonlen(prel+1, prer, postl, postr-1);
//        if(comlen % 2 ==1) flag = 1;
//        node* root = new node();
//        root->val = val;
//        root->left = build(prel+1, prel+comlen, postl, postl+comlen-1);
//        root->right = build(prel+comlen+1, prer, postl+comlen, postr-1);
//        return root;
//    }else{
//        return NULL;
//    }
//
//}
//void inorder(node * root){
//    if(root!=NULL){
//        inorder(root->left);
//        result.push_back(root->val);
//        inorder(root->right);
//    }
//}
//int main(){
//    scanf("%d", &N);
//    for (int i = 0; i < N; ++i) {
//        scanf("%d", &pre[i]);
//    }
//    for (int j = 0; j < N; ++j) {
//        scanf("%d", &post[j]);
//    }
//
//    node* root = build(0,N-1, 0, N-1);
//    if(flag == 1)printf("No\n");
//    else printf("Yes\n");
//
//    inorder(root);
//    for (int k = 0; k < result.size(); ++k) {
//        if(k!=0) printf(" ");
//        printf("%d", result[k]);
//    }
//    printf("\n");
//
//    return 0;
//}