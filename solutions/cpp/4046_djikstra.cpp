struct Node{
    int cost = 0;
    int row = 0; 
    int col = 0;
    int turns = 0;
    int dir = 4;

    bool operator>(const Node& rhs) const {
        return cost > rhs.cost;
    }
};

class Solution {

public:
    int minCost(vector<vector<int>>& grid, int k) {

        int n = grid.size(), m = grid[0].size();

        // [row][col][turns][dir]
        bool visited[75][75][76][5] = {};

        const vector<pair<int,int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

        priority_queue<Node, vector<Node>, greater<Node>> pq;
        pq.push({grid[0][0], 0, 0, 0, 4});

        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();

            if(visited[node.row][node.col][node.turns][node.dir]) continue;

            visited[node.row][node.col][node.turns][node.dir] = true;

            if(node.row == n-1 && node.col == m-1){
                return node.cost;
            }

            for(int dir=0; dir<4; dir++){
                Node next{};
                next.dir = dir;
                // increase number of turns if dir changes
                if(node.dir != 4 && node.dir != dir){
                    next.turns = node.turns + 1;
                } else {
                    next.turns = node.turns;
                }

                // if number of turns is > k  then skip
                if(next.turns > k) continue;
                
                // if next node is out of bounds skip
                int next_row = node.row + directions[dir].first;
                int next_col = node.col + directions[dir].second;
                if(next_row < 0 || next_row >= grid.size()) continue;
                if(next_col < 0 || next_col >= grid[0].size()) continue;

                // if already visited then skip
                if(visited[next_row][next_col][next.turns][next.dir]) continue;

                // copy data
                next.cost = node.cost + grid[next_row][next_col];
                next.row = next_row;
                next.col = next_col;

                pq.push(next);
            }
        }

        return -1;
    }
};
