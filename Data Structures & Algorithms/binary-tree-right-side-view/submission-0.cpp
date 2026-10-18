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

    vector<vector<int>>levelOrder(TreeNode *root){
        if(isEmpty(root)){
            return {};
        }

        queue<TreeNode *>q;
        vector<vector<int>>result;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int>levelOrderSubArray;
            for(int i = 0; i<size; i++){
                TreeNode *frontNode = q.front();
                levelOrderSubArray.push_back(frontNode->val);

                if(frontNode->left != NULL){
                    q.push(frontNode->left);
                }

                if(frontNode->right != NULL){
                    q.push(frontNode->right);
                }

                q.pop();
            }

            result.push_back(levelOrderSubArray);
        }

        return result;
    }

    vector<int> rightSideView(TreeNode* root) {
        if(isEmpty(root)){
            return {};
        }

        vector<vector<int>>levelOrderResult = levelOrder(root);
        vector<int>result;
        for(int i = 0;i<levelOrderResult.size(); i++){
            result.push_back(levelOrderResult[i][levelOrderResult[i].size()-1]);
        }

        return result;
    }
};
