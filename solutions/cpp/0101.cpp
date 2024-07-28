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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSymmetricRec(root->left, root->right);
    }

    bool isSymmetricRec(TreeNode* left, TreeNode* right){
        if(!left || !right) return left == right;
        return left->val == right->val && isSymmetricRec(left->left, right->right) && isSymmetricRec(left->right, right->left);
    }
};