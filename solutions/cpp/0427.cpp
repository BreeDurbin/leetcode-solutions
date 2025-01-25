/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return dfs(grid, 0, 0, n);
    }

    Node* dfs(vector<vector<int>>& grid, int r, int c, int n){
        bool is_leaf = true;
        int val = grid[r][c];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[r+i][c+j] != val){
                    is_leaf = false;
                    break;
                }
            }
        }

        if(is_leaf) return new Node(grid[r][c], true);

        n = n / 2;

        Node* node = new Node(grid[r][c], false);
        node->topLeft = dfs(grid, r, c, n);
        node->topRight = dfs(grid, r, c+n, n);
        node->bottomLeft = dfs(grid, r+n, c, n);
        node->bottomRight = dfs(grid, r+n, c+n, n);
        
        return node;
    }

};
