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
    int getMinimumDifference(TreeNode* root) {
        vector<int> sorted;
        traverse(root, sorted);
        int ans = INT_MAX;
        for(int i=1; i<sorted.size(); i++){
            ans = min(ans, abs(sorted[i] - sorted[i-1]));
        }
        return ans;
    }

    void traverse(TreeNode* node, vector<int>& out){
        if(node == nullptr) return;
        traverse(node->left, out);
        out.push_back(node->val);
        traverse(node->right, out);
    }
};