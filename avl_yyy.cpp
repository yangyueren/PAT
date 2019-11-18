//
// Created by yryang on 2019/9/7.
//

#include "iostream"
#include "vector"
using namespace std;

struct Node{
    int val;
    struct Node* left;
    struct Node* right;
    Node(int a){
        this->val = a;
        this->left = NULL;
        this->right = NULL;
    }
};
typedef struct Node *pnode;

int height(pnode root){
    if(root == NULL){
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

pnode ll(pnode root){
    if(root == NULL) return NULL;
    pnode son = root->left;
    root->left = son->right;
    son->right = root;
    return son;
}

pnode rr(pnode root){
    pnode son = root->right;
    root->right = son->left;
    son->left = root;
    return son;
}

pnode lr(pnode root){
    root->left = rr(root->left);
    return ll(root);
}

pnode rl(pnode root){
    root->right = ll(root->right);
    return rr(root);
}

pnode maintain(pnode root){
    if(height(root->left) - height(root->right) == 2){
        if(height(root->left->left) >= height(root->left->right)){
            root = ll(root);
        } else{
            root = lr(root);
        }
    }else if (height(root->left) - height(root->right) == -2){
        if(height(root->right->left) <= height(root->right->right)){
            root = rr(root);
        } else{
            root = rl(root);
        }
    }
    return root;
}

pnode insert(pnode root, int val){
    if (root == NULL) return new Node(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return maintain(root);

}

void preorder(pnode root){
    if(root == NULL) return;
    else{
        cout << root->val<< " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(pnode root){
    if(root == NULL) return;
    else{
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

int main(){
    pnode root = NULL;
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 9);
    root = insert(root, 8);
    preorder(root);
    cout << endl;
    inorder(root);
    return 0;
}