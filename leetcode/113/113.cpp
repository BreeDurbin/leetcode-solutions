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
    vector<vector<int>> result;
public:

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        result.clear();
        if(!root)return result;
        vector<int> path;
        traverse(root,path,targetSum);
        return result;
    }

    void traverse(TreeNode* root, vector<int>& path, int remainingSum) {
        //if node is null
        if(!root) return;
        //if it is a leaf node
        if(!root->left && !root->right){
            path.push_back(root->val);
            if(remainingSum == root->val) result.push_back(path);
            path.pop_back();
            return;
        } 
        // if it is a branch node
        path.push_back(root->val);
        int temp = root->val;
        traverse(root->left, path, remainingSum-temp);
        traverse(root->right, path, remainingSum-temp);
        path.pop_back();
    }
};