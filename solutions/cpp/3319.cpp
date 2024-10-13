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

    vector<int> v;

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        populateHeap(root);
        if(k > v.size()) return -1;
        sort(v.begin(), v.end(), greater<int>());
        return v[k - 1];
    }

    int populateHeap(TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right){
            v.push_back(1);
            return 1;
        }
        int l = populateHeap(root->left), r = populateHeap(root->right);
        if(l==-1||r==-1) return -1;
        int ans = 0;
        if(r == l){ 
            ans = 1 + r + l;
            v.push_back(ans); //populate heap with size of this subtree
            return ans;
        }
        return -1; //return size of prefect subtree
    }

};
