#include<bits/stdc++.h>

using namespace std;

int deepest = 0;
int inorder(TreeNode* root, int level){
    if(root->left != NULL || root->right != NULL){
        int res = 0;
        if(root->left != NULL){
            res += inorder(root->left, level + 1);
        }
        if(root->right != NULL){
            res += inorder(root->right, level + 1);
        }
        return res;
    } else {
        if (level == deepest){
            return root->val;
        }
        return 0;
    }
}

void find(TreeNode* root, int level){
    if(root != NULL){
        if(level > deepest)
            deepest = level;
        find(root->left, level + 1);
        find(root->right, level + 1);
    }
}

int deepestLeavesSum(TreeNode* root) {
    find(root, 0);
    return inorder(root, 0);
}
