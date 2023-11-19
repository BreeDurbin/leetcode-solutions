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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        v1 = getLeaves(root1);
        v2 = getLeaves(root2);
        if(v1.size() != v2.size()) return false;
        for(int i=0; i<v1.size(); i++){
            if(v1[i] != v2[i]) return false;
        }
        return true;
    }

    vector<int> getLeaves(TreeNode* root){
        vector<int> ans;
        if(root){
            if(root->left) {
                auto temp = getLeaves(root->left);
                ans.insert(ans.end(), temp.begin(), temp.end());
            }
            if(root->right){
                auto temp = getLeaves(root->right);
                ans.insert(ans.end(), temp.begin(), temp.end());
            }
            if(ans.size() == 0) ans.push_back(root->val);
        }
        return ans;
    }
};