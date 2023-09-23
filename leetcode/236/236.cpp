/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q) return root;
        auto right = lowestCommonAncestor(root->right, p, q);
        auto left = lowestCommonAncestor(root->left, p, q);
        if(left && right) return root;
        if(left && !right) return left;
        if(right && !left) return right;
        return nullptr;
    }
};