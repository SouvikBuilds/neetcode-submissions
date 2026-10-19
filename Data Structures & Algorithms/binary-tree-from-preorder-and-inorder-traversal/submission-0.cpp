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
    TreeNode *createNode(int val){
        TreeNode *newNode = new TreeNode(val);
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0){
            return NULL;
        }

        vector<int>leftInorderTree;
        vector<int>rightInorderTree;
        TreeNode *root = createNode(preorder[0]);
        for(int i = 0; i<inorder.size(); i++){
            if(inorder[i] == preorder[0]){
                for(int j = 0;j<i;j++){
                    leftInorderTree.push_back(inorder[j]);
                }

                for(int j = i+1; j<inorder.size(); j++){
                    rightInorderTree.push_back(inorder[j]);
                }
            }
        }

        vector<int>leftPreOrderTree(preorder.begin()+1,
        preorder.begin()+leftInorderTree.size()+1);

        vector<int>rightPreOrderTree(preorder.begin()+leftInorderTree.size()+1,
        preorder.end());

        root->left = buildTree(leftPreOrderTree,leftInorderTree);
        root->right = buildTree(rightPreOrderTree,rightInorderTree);

        return root;
    }
};
