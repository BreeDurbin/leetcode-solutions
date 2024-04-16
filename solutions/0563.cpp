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
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        return abs(sum(root->left) - sum(root->right)) + findTilt(root->left) + findTilt(root->right);
    }
    
    int sum(TreeNode* node){
        if(!node) return 0;
        return node->val + sum(node->left) + sum(node->right);
    }
};