//
// Created by yryang on 2019/9/7.
//

#include "iostream"
#include "map"
#include "string"
#include "vector"
#include "algorithm"
#include "limits.h"
using namespace std;

struct Node{
    int val;
    Node* left;
    Node * right;
    Node(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
typedef struct Node *pnode;




int pre[10005];
int ino[10005];
int N;

void inorder(pnode root){
    if(root!=NULL){
        inorder(root->left);
        cout << root->val;
        inorder(root->right);
    }
}

pnode buildtree(int prel, int prer, int inol, int inor){
    if(prel <= prer){
        int val = pre[prel];
        int index = -1;
        for (int i = inol; i <= inor; ++i) {
            if(val == ino[i]){
                index = i;
            }
        }
        int leftlength = index-inol;
        pnode root = new Node(val);
        root->left = buildtree(prel+1, prel+leftlength, inol, index-1);
        root->right = buildtree(prel+leftlength+1, prer, index+1, inor);
        return root;

    } else{
        return NULL;
    }
}
int lca(pnode root, int x, int y){
    if(root == NULL) return 0;

    int f1 = lca(root->left, x, y);
    int f2 = lca(root->right, x, y);
    if(f1 == -1 || f2 == -1){
        return -1;
    }
    if(f1 > 0 && f2 > 0){
        printf("LCA of %d and %d is %d.\n", x, y, root->val);
        return -1;
    }

    if(root->val == x && (f1 > 0 || f2 > 0)) {
        printf("%d is an ancestor of %d.\n", x, y);
        return -1;
    }
    else if(root->val == y && (f1 > 0 || f2 > 0)) {
        printf("%d is an ancestor of %d.\n", y, x);
        return -1;
    } else if(root->val == x){
        return 1;
    }else if(root->val == y){
        return 2;
    }else if(f1 > 0){
        return f1;
    }else if(f2 > 0){
        return f2;
    } else{
        return 0;
    }

}
void findlca(pnode root, int x, int y){
    int  f = lca(root, x, y);
    if(f == 1) printf("ERROR: %d is not found.\n", y);
    if(f==2) printf("ERROR: %d is not found.\n", x);
    if(f==0) printf("ERROR: %d and %d are not found.\n", x, y);
}

int main(){
    int M;
    cin >> M >> N;
    for (int i = 0; i < N; ++i) {
        cin >> ino[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> pre[i];
    }
    pnode root = buildtree(0,N-1, 0, N-1);
//    inorder(root);
    for (int j = 0; j < M; ++j) {
        int x ,y;
        cin >> x >> y;
        findlca(root, x, y);
    }

    return 0;
}