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

    int height(TreeNode *root){
        if(isEmpty(root)){
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return 1+max(leftHeight,rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        if(isEmpty(root)){
            return true;
        }

        int leftHeightResult = height(root->left);
        int rightHeightResult = height(root->right);
        int diff = abs(leftHeightResult-rightHeightResult);
        if(diff>1){
            return false;
        }

        bool leftResult = isBalanced(root->left);
        bool rightResult = isBalanced(root->right);

        return leftResult && rightResult;
    }
};
