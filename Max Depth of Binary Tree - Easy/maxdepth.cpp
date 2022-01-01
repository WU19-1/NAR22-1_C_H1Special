#include<stdio.h>

int max = 0;
void inorder(TreeNode* root, int level){
    if(root != NULL){
        inorder(root->left, level + 1);
        inorder(root->right, level + 1);
        
        if(level > max){
            max = level;
        }
    }
}

int maxDepth(TreeNode* root) {
    max = 0;
    inorder(root, 1);
    return max;
}

int main(){
	
	return 0;
}
