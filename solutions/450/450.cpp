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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root) 
            if(root->val > key) root->left = deleteNode(root->left, key);//binary search for key left branch
            else if(root->val < key) root->right = deleteNode(root->right, key);//binary search for key right branch
            else{//found the key
                if(!root->left && !root->right) return nullptr; //no kids delete
                if(!root->left || !root-> right)  // one kid replace with the kid.
                    return root->left ? root->left : root->right;
                else { // two children case. Replace using the right most child of the left child of the deleted node
                    TreeNode *temp=root->left;// left child of the node to be deleted
                    while(temp->right) temp=temp->right; // traverse to the deepest right child
                    temp->right=root->right; // inorder predecessor of the deleted node. We swap this into where the deleted node was.
                    return root->left;
                }
            }
        return root;
    }   
};