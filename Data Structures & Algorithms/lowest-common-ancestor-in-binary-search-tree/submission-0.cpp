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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(isEmpty(root)){
            return NULL;
        }

        while(root != NULL){
            if(root->val < p->val && root->val < q->val){
                root = root->right;
            }else if(root->val>p->val && root->val>q->val){
                root = root->left;
            }else{
                break;
            }
        }

        return root;
    }
};
