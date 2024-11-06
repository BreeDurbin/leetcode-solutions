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
    int sumNumbers(TreeNode* root) {
        return sum(root, 0);
    }

    int sum(TreeNode* node, int cur){
        if(!node) return 0;
        cur = 10 * cur + node->val;
        if(!node->left && !node->right) return cur;
        return sum(node->left, cur) + sum(node->right, cur);
    }
};
