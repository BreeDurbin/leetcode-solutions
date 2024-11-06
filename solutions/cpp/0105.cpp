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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0,0,inorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int p, int left, int right){
        if(left > right || p > preorder.size() - 1) return nullptr;

        TreeNode* root = new TreeNode(preorder[p]);

        int mid = 0;
        for(int i=left; i<=right; i++){
            if(inorder[i] == preorder[p]){
                mid = i;
                break;
            }
        }

        root->left = build(preorder, inorder, p + 1, left, mid - 1);
        root->right = build(preorder, inorder, p + 1 + mid - left, mid + 1, right);
        return root;
    }
    
 
};
