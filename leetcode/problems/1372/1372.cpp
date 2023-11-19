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
    int total=0;

    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        zig(root->right,0);
        zag(root->left,0);
        return total;
    }

    //right
    void zig(TreeNode* root, int sum){
        total = max(total,sum);
        if(!root) return;
        zag(root->left,sum+1);
        zig(root->right,0);
    }

    //left
    void zag(TreeNode* root, int sum){
        total = max(total,sum);
        if(!root) return;
        zig(root->right,sum+1);
        zag(root->left,0);
    }

};