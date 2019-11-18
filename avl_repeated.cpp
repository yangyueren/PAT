//
// Created by yryang on 2019/9/6.
//

/*
	a simple implement AVL which can have same value nodes.
	written by Jiang Tan
	2019.08.30
*/
#include <bits/stdc++.h>
using namespace std;

struct tree{
    int data;
    tree *left, *right;
    int size, height, cnt;
    tree(int a){
        data = a; left = right = NULL;
        height = size = cnt = 1;
    }
};

int height(tree *root) { return root ? root->height : 0; }

int size(tree *root) { return root ? root->size : 0; }

tree* rr(tree* root)
{
    tree *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root->height = max(height(root->left), height(root->right))+1;
    root->size = size(root->left) + size(root->right)+root->cnt;
    temp->height = max(height(temp->left), height(temp->right))+1;
    temp->size = size(temp->left) + size(temp->right)+temp->cnt;
    return temp;
}

tree* ll(tree* root)
{
    tree *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root->height = max(height(root->left), height(root->right))+1;
    root->size = size(root->left) + size(root->right)+root->cnt;
    temp->height = max(height(temp->left), height(temp->right))+1;
    temp->size = size(temp->left) + size(temp->right)+temp->cnt;
    return temp;
}

tree *rl(tree *root)
{
    root->right = ll(root->right);
    return rr(root);
}

tree* lr (tree *root)
{
    root->left = rr(root->left);
    return ll(root);
}

tree* maintain(tree* root)
{
    if (height(root->left) - height(root->right) == 2)
    {
        if (height(root->left->left) >= height(root->left->right)) root = ll(root);
        else root = lr(root);
    }
    else if (height(root->left) - height(root->right) == -2)
    {
        if (height(root->right->right) >= height(root->right->left)) root = rr(root);
        else root = rl(root);
    }
    root->height = max(height(root->left), height(root->right))+1;
    root->size = size(root->left) + size(root->right)+root->cnt;
    return root;
}

tree* insert(tree *root, int data) //insert operation
{
    if (!root) return new tree(data);
    if(data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    else ++root->cnt;
    return maintain(root);
}

tree* del(tree* root, int data, bool del_node=false) // delete operation
{
    if(data < root->data) root->left = del(root->left, data, del_node);
    else if (data > root->data) root->right = del(root->right, data, del_node);
    else
    {
        if (root->cnt > 1 && !del_node) --root->cnt;
        else
        {
            tree* temp;
            if (root->right)
            {
                temp = root->right;
                while (temp->left) temp = temp->left;
                root->data = temp-> data; root->cnt = temp->cnt;
                root->right = del(root->right, root->data, true);
            }
            else
            {
                temp = root;
                root = root->left;
                delete temp;
                return root;
            }
        }
    }
    return maintain(root);
}

int findk(tree *root, int k) //������Ϊ��kС����
{
    if (k <= size(root->left)) return findk(root->left, k);
    else if (k <= size(root->left)+root->cnt) return root->data;
    else return findk(root->right, k-size(root->left)-root->cnt);
}

int query(tree* root, int data) //��ĳ���������� (����ж��������ȡ��С������)
{
    if (data > root->data) return size(root->left)+root->cnt+query(root->right, data);
    else if(data == root->data) return size(root->left)+1;
    else return query(root->left, data);
}

int pre(tree* root, int data) //��ĳ���ڵ��ǰ��
{
    int ret;
    while (root)
    {
        if (root->data < data)
        {
            ret = root->data;
            root = root->right;
        }
        else root = root->left;
    }
    return ret;
}

int post(tree* root, int data) //��ĳ���ڵ�ĺ��
{
    int ret;
    while (root)
    {
        if (root->data > data)
        {
            ret = root->data;
            root = root->left;
        }
        else root = root->right;
    }
    return ret;
}

int main(void)
{
    int q, temp;
    scanf("%d", &q);
    tree *root = NULL;
    while (q--)
    {
        int op; scanf("%d %d", &op, &temp);
        if (op == 1) root = insert(root, temp);
        else if (op == 2) root = del(root, temp);
        else if (op == 3) printf("%d\n", query(root, temp));
        else if (op == 4) printf("%d\n", findk(root, temp));
        else if (op == 5) printf("%d\n", pre(root, temp));
        else if (op == 6) printf("%d\n", post(root, temp));
    }
}

