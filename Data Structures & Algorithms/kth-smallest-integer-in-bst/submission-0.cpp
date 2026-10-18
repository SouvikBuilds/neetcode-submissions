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
    void inOrderArray(TreeNode *root,vector<int>&nodes){
        if(isEmpty(root)) return;

        inOrderArray(root->left,nodes);
        nodes.push_back(root->val);
        inOrderArray(root->right,nodes);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(isEmpty(root)) return -1;
        vector<int>nodes;
        inOrderArray(root,nodes);
        if(k>nodes.size()) return -1;

        return nodes[k-1];
    }
};
