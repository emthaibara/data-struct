#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct TreeNode{
    struct Node* left;
    struct Node* right;
    int val;
}TreeNode;

TreeNode* root;

//递归遍历二叉树
void preOrderByRecursion(TreeNode* root){
    if(root == NULL)return;
    printf("%d ",root->val);
    preOrderByRecursion(root->left);
    preOrderByRecursion(root->right);
}
void inOrderByRecursion(TreeNode* root){
    if(root == NULL)return;
    preOrderByRecursion(root->left);
    printf("%d ",root->val);
    preOrderByRecursion(root->right);
}
void postOrderByRecursion(TreeNode* root){
    if(root == NULL)return;
    preOrderByRecursion(root->left);
    preOrderByRecursion(root->right);
    printf("%d ",root->val);
}
//利用栈迭代遍历二叉树
void preOrderByStack(TreeNode* root){
    TreeNode* stack[2000];
    TreeNode* cur = root;
    int top = 0;
    while(top > 0){
        while(cur != NULL){
            printf("%d ",cur->val);
            stack[top++] = cur;
            cur = cur->left;
        }
        //回退
        cur = stack[--top];
        cur = cur->right;
    }
    printf("\n");
}
void inOrderByStack(TreeNode* root){
    TreeNode* stack[2000];
    TreeNode* cur = root;
    int top = 0;
    while(top > 0){
        while(cur != NULL){
            stack[top++] = cur;
            cur = cur->left;
        }
        //回退
        cur = stack[--top];
        printf("%d ",cur->val);
        cur = cur->right;
    }
    printf("\n");
}
void postOrderByStack(TreeNode* root){
    TreeNode* stack[2000];
    TreeNode* cur = root;
    TreeNode* pre = NULL;
    int top = 0;
    while(top > 0 || cur != NULL){
        //左树走到底
        while(cur != NULL){
            stack[top++] = cur;
            cur = cur->left;
        }
        //回溯到上一个节点
        cur = stack[--top]; //弹出来的节点左子树肯定走到底，右子树不确定是否走到底
        if(cur->right == NULL || cur->right == pre){ //走到底才访问，pre用
            printf("%d ",cur->val);
            pre = cur;
            cur = NULL;
        }else{ //没走到底就继续遍历右子树
            stack[top++] = cur;
            cur = cur->right;
        }
    }
    printf("\n");
}
//还原二叉树 前序+中序
TreeNode* recoverFromPreOrderAndInOrder(int* preOrder,int* InOrder){

}
//还原二叉树 后序+中序
TreeNode* recoverFromPostOrderAndInOrder(int* postOrder,int* InOrder){
    
}   
//还原二叉树 中序+层序
TreeNode* recoverFromLevelOrderAndInOrder(int* levelOrder,int* InOrder){

}
//还原二叉树 前序+后序
TreeNode* recoverFromPreOrderAndPostOrder(int* preOrder,int* postOrder){

}
//随便构建一颗二叉树，用于测试
TreeNode* genBinaryTree(){

}
int main(){

}