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
    int maxLevelSum(TreeNode* root) {
        unordered_map<int, int> levels;
        bfs(root,1,levels);
        int ans = INT_MIN, max_sum = INT_MIN;
        for(auto& [key, val] : levels){
            if(max_sum < val){
                max_sum = val;
                ans = key;
                cout << "LEVEL: " << ans << " MAX_SUM " << max_sum << endl;
            } else if (max_sum == val){
                ans = min(ans,key);
            }
        }
        return ans;
    }

    void bfs(TreeNode* root, int level, unordered_map<int, int>& levels){
        if(root == nullptr) return;
        levels[level]+=root->val;
        bfs(root->right,level+1,levels);
        bfs(root->left,level+1,levels);
    }
};