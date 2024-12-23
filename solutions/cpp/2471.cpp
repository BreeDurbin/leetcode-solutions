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
    int minimumOperations(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        int levelSize = 1;
        queue<TreeNode*> q;
        q.push(root);

        //first do a level order traversal
        //so bfs with a queue 
        while(!q.empty()){

            //add next level in
            vector<int> level(levelSize);
            int nextLevelSize = 0;

            //for each node in level 
            for(int i = 0; i<levelSize; i++){
                auto node = q.front();
                q.pop();
                //for each nod ein level 
                //add to list<node> level
                level[i] = node->val;
                //then add the next level to the queue
                if(node->left){
                    q.push(node->left);
                    nextLevelSize++;
                }
                if(node->right){
                    q.push(node->right);
                    nextLevelSize++;
                }
            }

            //selection sort the level array and += it to the ans
            ans += selectionSort(level);
            //update current level to nextLevel
            levelSize = nextLevelSize;
        }

        return ans;
        
    }

    int selectionSort(vector<int>& v){
        int n = v.size(), count = 0;
        for(int i = 0; i < n-1; i++){
            int minj = i;
            for(int j = i+1; j < n; j++){
                if(v[j] < v[minj]){
                    minj = j;
                }
            }
            //swap
            if(i != minj){
                count++;
                int temp = v[i];
                v[i] = v[minj];
                v[minj] = temp;
            }
        }
        return count;
    }
};
