/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isEmpty(TreeNode *root){
        return root == NULL;
    }

    void swapPointer(TreeNode **ptr1, TreeNode **ptr2){
        TreeNode *temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;
    }

    TreeNode* invertTree(TreeNode* root) {
        if(isEmpty(root)){
            return NULL;
        }

        swapPointer(&root->left, &root->right);
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);

        return root;
    }
};
