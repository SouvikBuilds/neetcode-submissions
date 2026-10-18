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

    int ct = 0;
    void find(TreeNode *root, int mx){
        if(isEmpty(root)) return;
        if(root->val>=mx) ct++;

        find(root->left,max(mx,root->val));
        find(root->right,max(mx,root->val));
    }
    int goodNodes(TreeNode* root) {
        if(isEmpty(root)) return 0;
        find(root,INT_MIN);
        return ct;
    }
};
