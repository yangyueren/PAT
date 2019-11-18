//
// Created by yryang on 2019/8/25.
//


#include "stdio.h"
#include "iostream"
#include "string"
#include "map"
#include "vector"
#include "limits.h"
#include "cmath"
#include "queue"
using namespace std;

struct Node{
    int val;
    struct Node *left;
    struct Node *right;
};
typedef struct Node *pNode;

int n;
int pos[100];
int ino[100];
pNode root = nullptr;

pNode reConstructTree(int inbegin, int inend, int posbegin, int posend){
    if (inbegin > inend) return nullptr;
    if (inbegin == inend) {
        pNode node = new struct Node;
        node->val = ino[inbegin];
        node->left = nullptr;
        node->right = nullptr;
        return node;
    }
    int midval = pos[posend];
    pNode node = new struct Node;
    node->val = midval;
    int clip = 0;
    for (int i = inbegin; i <= inend; ++i) {
        if (midval == ino[i]){
            clip = i;
            break;
        }
    }
    int leftlength = clip-inbegin;
    int rightlength = inend - clip;
    node->left = reConstructTree(inbegin, clip-1, posbegin, posbegin+leftlength-1 );
    node->right = reConstructTree(clip+1, inend, posend-rightlength, posend-1);
    return node;

}

void inorder(pNode root){
    if(root->left != nullptr) inorder(root->left);
    cout << root->val << " ";
    if(root->right != nullptr) inorder(root->right);
}
int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> pos[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> ino[i];
    }
    root = reConstructTree(0, n-1, 0, n-1);
    queue<pNode> qu;
    if(root != nullptr)
        qu.push(root);
    while (!qu.empty()){
        pNode cur = qu.front();
        qu.pop();//pop并不返回东西
        if(cur->left) qu.push(cur->left);
        if(cur->right) qu.push(cur->right);
        cout << cur->val;
        if(!qu.empty()) cout << " ";
    }
//    inorder(root);
    return 0;
}