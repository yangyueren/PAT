//
// Created by yryang on 2019/9/12.
//

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
#include "stack"
using namespace std;


struct node{
    node* left;
    node* right;
    int val;
};
int ino[35];
int pre[35];
int N;

node* build(int prel, int prer, int inl, int inr){
    if(prel<= prer){
        int val = pre[prel];
        int index = -1;
        for (int i = inl; i <=  inr; ++i) {
            if(val == ino[i]){
                index = i;
                break;
            }
        }
        int leftlength = index - inl;
        node* root = new node();
        root->val = val;
        root->left = build(prel+1, prel+leftlength, inl, index-1);
        root->right = build(prel+leftlength+1, prer, index+1, inr);
        return root;
    } else{
        return NULL;
    }
}

int ddd = 0;
void post(node* root){
    if(root == NULL) return;
    else {
        post(root->left);
        post(root->right);
        if(ddd != 0){
            printf(" ");
        }
        ddd=1;
        printf("%d", root->val);
    }
}
int main(){
    scanf("%d", &N);
    getchar();
    int k=2*N;
    string s;
    stack<int> stk;
    int prenum=0;
    int inonum=0;
    for (int i = 0; i < k; ++i) {
        getline(cin, s);
        if(s.size() > 3){
            string a = s.substr(5, s.size()-5);
            int b = stoi(a);
            stk.push(b);
            pre[prenum++] = b;
        } else{
            ino[inonum++] = stk.top();
            stk.pop();
        }
    }
    node* root = build(0, prenum-1, 0, inonum-1);
    post(root);
}