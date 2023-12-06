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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        return goodNodesRec(root, INT_MIN);
    }

    int goodNodesRec(TreeNode* root, int curMax){
        if(!root) return 0;
        if(root->val >= curMax) return 1 + goodNodesRec(root->left, root->val) + goodNodesRec(root->right, root->val);
        else return goodNodesRec(root->left, curMax) + goodNodesRec(root->right, curMax);
    }
};