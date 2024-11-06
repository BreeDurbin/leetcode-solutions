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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> map;
        for(int i=0; i<inorder.size(); i++){
            map[inorder[i]] = i;
        }
        int postOrderIndex = postorder.size() - 1;
        return build(postorder, map, postOrderIndex,0,inorder.size()-1);
    }

    TreeNode* build(vector<int>& postorder, unordered_map<int,int>& map, int& postOrderIndex, int left, int right){
        if(left > right || postOrderIndex > postorder.size() - 1) return nullptr;

        TreeNode* root = new TreeNode(postorder[postOrderIndex]);

        int mid = map[postorder[postOrderIndex--]];
        
        root->right = build(postorder, map, postOrderIndex, mid + 1, right);
        root->left = build(postorder, map, postOrderIndex, left, mid - 1);
        
        return root;
    }
    
};
