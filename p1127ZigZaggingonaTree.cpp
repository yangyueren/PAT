//
// Created by yryang on 2019/9/16.
//

//用stack做会比较好

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
    node * left;
    node * right;
    int val;
    int dep;
    node(int val){
        left = NULL;
        right = NULL;
        this->val = val;
        dep = -1;
    }
};
int N;
int ino[35];
int post[35];
vector<int> re;

node* build(int inl, int inr, int postl, int postr){
    if(postl <= postr){
        int val = post[postr];
        int index = -1;
        for (int i = inl; i <= inr ; ++i) {
            if(ino[i] == val){
                index = i;
                break;
            }
        }
        int leftlen = index - inl;
        node* root = new node(val);
        root->left = build(inl, index-1, postl, postl+leftlen-1);
        root->right = build(index+1, inr, postl+leftlen, postr-1);
        return root;

    } else{
        return NULL;
    }

    return NULL;
}
//void depth(node* root, int dep){
//    if(root != NULL){
//        root->dep = dep;
//        if(root->left != NULL) depth(root->left, dep+1);
//        if(root->right != NULL) depth(root->right, dep+1);
//    }
//    return ;
//}
void levelorder(node* root){
    vector<node*> p;
    vector<node*> q;
    q.push_back(root);
    p = q;
    int flag = 0;
    while (!p.empty()){
        q.clear();
        while (!p.empty()){
            node * now;
            if(flag == 1){
                now = *p.begin();
                p.erase(p.begin());
            } else{
                now = *p.rbegin();
                p.pop_back();
            }
            if(now != NULL){
                re.push_back(now->val);
                if(flag == 1){
                    q.push_back(now->left);
                    q.push_back(now->right);
                } else{
                    q.insert(q.begin(),now->right);
                    q.insert(q.begin(),now->left);
                }
            }
        }
        flag = 1 - flag;
        p = q;
    }

}
int main(){
    cin >> N;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &ino[i]);
    }
    for (int j = 0; j < N; ++j) {
        scanf("%d", &post[j]);
    }
    node* root = build(0,N-1, 0, N-1);
    depth(root, 0);
    levelorder(root);
    for (int k = 0; k < re.size(); ++k) {
        if(k!=0) printf(" ");
        cout << re[k];
    }
    return 0;
}