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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ary;
        postorderTraversal(root, ary);
        return ary;
    }
private: 
    void postorderTraversal(TreeNode* root, vector<int>& postorder) {
        if(!root) return;
        postorderTraversal(root->left, postorder);
        postorderTraversal(root->right, postorder);
        postorder.push_back(root->val);
    }
};