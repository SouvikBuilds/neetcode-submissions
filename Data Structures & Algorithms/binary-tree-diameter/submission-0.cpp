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
    int maxDiameter = 0;
    int diameterRecursion(TreeNode *root){
        if(isEmpty(root)){
            return 0;
        }

        int leftHeight = diameterRecursion(root->left);
        int rightHeight = diameterRecursion(root->right);
        if(leftHeight+rightHeight>maxDiameter){
            maxDiameter = leftHeight+rightHeight;
        }

        return 1+max(leftHeight,rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0;
        diameterRecursion(root);
        return maxDiameter;
    }
};
