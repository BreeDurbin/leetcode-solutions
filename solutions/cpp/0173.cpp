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
class BSTIterator {
public:

    vector<int> array;
    int i = 0;

    BSTIterator(TreeNode* root) {
        dfs(root);
    }

    void dfs(TreeNode* node){
        if(!node) return;
        dfs(node->left);
        array.push_back(node->val);
        dfs(node->right);
    }
    
    int next() {
        return array[i++];
    }
    
    bool hasNext() {
        return i < array.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
