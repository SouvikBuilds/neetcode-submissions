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
    bool isEmpty(TreeNode *root) {
        return root == NULL;
    }
    int findSumRecursion(TreeNode *root, int &res){
        if(isEmpty(root)) return 0;

        int l = max(0,findSumRecursion(root->left,res));
        int r = max(0,findSumRecursion(root->right,res));

        res = max(res,l+r+root->val);
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        findSumRecursion(root,res);
        return res;
    }
};
