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
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        dfs(root);
    }

private:
    TreeNode* dfs(TreeNode* node){
        if(!node) return nullptr;
        auto leftTail = dfs(node->left);
        auto rightTail = dfs(node->right);
        if(node->left){
            leftTail->right = node->right;
            node->right = node->left;
            node->left = nullptr;
        }
        if(rightTail) return rightTail;
        if(leftTail) return leftTail;
        return node;
    }
};