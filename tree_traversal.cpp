//
// Created by yryang on 2019/9/6.
//

#include "iostream"
#include "string"
#include "vector"
using namespace std;

int pre[] = {1,2,4,5,3,6};
int inorder[] = {4,2,5,1,3,6};
int post[] = {4,5,2,6,3,1};

struct node{
    int val;
    struct node* left;
    struct node* right;
};
typedef struct node *pnode;

pnode preandin(int prel, int prer, int inl, int inr){
    if(prel <= prer){
        pnode root = new struct node;
        root->val = pre[prel];
        int val = pre[prel];
        int inindex = 0;
        for (int i = inl; i <= inr; ++i) {
            if(inorder[i] == val){
                inindex = i;
                break;
            }
        }
        int lefttreelength = inindex-inl;
        root->left = preandin(prel+1, prel+lefttreelength, inl, inindex-1);
        root->right = preandin(prel+lefttreelength+1, prer, inindex+1, inr);
        return root;

    } else{
        return nullptr;
    }

}
void postorder_traversal(pnode root){
    if (root!=nullptr){
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout << root->val << " ";
    }
}

int height(pnode root){
    if(root==NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}

bool is_the_same(pnode root1, pnode root2){
    if (root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 == NULL || root2 == NULL){
        return false;
    }
    if(root1->val != root2->val){
        return false;
    }
    return is_the_same(root1->left, root2->left) && is_the_same(root1->right, root2->right);
}

int main(){
    pnode root = preandin(0, 5, 0, 5);
    postorder_traversal(root);
    cout << height(root);
    return 0;
}