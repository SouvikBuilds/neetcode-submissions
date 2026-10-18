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


    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(isEmpty(p) && isEmpty(q)){
            return true;
        }

        if((isEmpty(p) && !isEmpty(q)) || (!isEmpty(p) && isEmpty(q))){
            return false;
        }

        if(p->val != q->val){
            return false;
        }

        bool leftResult = isSameTree(p->left,q->left);
        bool rightResult = isSameTree(p->right,q->right);

        return leftResult && rightResult;
    }
};
