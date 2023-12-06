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

    int matches=0;

    int pathSum(TreeNode* root, int sum) {
        if(root){
          dfs(root,sum);
          pathSum(root->right, sum);
          pathSum(root->left, sum);
        }
        return matches;
    }

    void dfs(TreeNode* root, long sum){
        if(root->val==sum) matches++;
        if(root->right) dfs(root->right,sum-root->val);
        if(root->left) dfs(root->left,sum-root->val);
    }
};