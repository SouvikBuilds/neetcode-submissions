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

    bool isIdentical(TreeNode *root1, TreeNode *root2){
        if(isEmpty(root1) && isEmpty(root2)){
            return true;
        }

        if(isEmpty(root1) || isEmpty(root2)){
            return false;
        }

        if(root1->val != root2->val){
            return false;
        }

        bool leftResult = isIdentical(root1->left, root2->left);
        bool rightResult = isIdentical(root1->right, root2->right);

        return leftResult && rightResult;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(isEmpty(root)){
            return false;
        }

        if(isEmpty(subRoot)){
            return true;
        }

        if(isIdentical(root, subRoot)){
            return true;
        }

        bool leftResult = isSubtree(root->left, subRoot);
        bool rightResult = isSubtree(root->right, subRoot);

        return leftResult || rightResult;
    }
};
