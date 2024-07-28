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
    int ans = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans;
    }

    int solve(TreeNode* node){
        if(!node) return 0;
        int left = solve(node->left);
        int right = solve(node->right);
        ans = max(ans, left + right);
        return 1 + max(left, right);
    }
};