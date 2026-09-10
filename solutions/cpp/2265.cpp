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


struct Data {
    int sum = 0;
    int n = 0; 
};

class Solution {
public:

    int count = 0;

    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return count;
    }


    Data helper(TreeNode* node){
        if(node == nullptr) return {};

        Data left = helper(node->left);
        Data right = helper(node->right);

        int sum = node->val + left.sum + right.sum;
        int n = 1 + left.n + right.n;

        if(node->val == sum / n) count++;

        return {sum, n};
    }

};
