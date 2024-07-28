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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        ans.push_back(root->val);
        if(!root->left && !root->right) return ans;
        traverseLeft(root->left, ans);
        inorder(root, ans);
        traverseRight(root->right, ans);
        return ans;
    }

    void traverseLeft(TreeNode* node, vector<int>& v){
        auto cur = node;
        while(cur){
            if(cur->left || cur->right) v.push_back(cur->val);
            if(cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }

    void traverseRight(TreeNode* node, vector<int>& v){
        stack<int> s;
        auto cur = node;
        while(cur){
            if(cur->left || cur->right) s.push(cur->val);
            if(cur->right) cur = cur->right;
            else cur = cur->left;
        }

        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
    }

    void inorder(TreeNode* node, vector<int>& v){
        if(!node) return;
        inorder(node->left, v);
        if(!node->left && !node->right) v.push_back(node->val);
        inorder(node->right, v);
    }
};