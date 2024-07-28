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
    string tree2str(TreeNode* root) {
        if(!root) return "";
        string s = "";
        s = to_string(root->val);
        string temp1 = tree2str(root->left);
        s += temp1 == "" ? "" : "(" + temp1 + ")";
        string temp2 = tree2str(root->right);
        if(temp1 == "" && temp2 != "") s+= "()";
        s += temp2 == "" ? "" : "(" + temp2 + ")";
        return s;
    }
};