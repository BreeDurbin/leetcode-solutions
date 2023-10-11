class Solution {
public:
    int bottom, left, top, right, fresh_oranges_count = 0;
    int empty_space = 0, fresh_orange = 1, rotten_orange = 2, visited = 0;
    queue<pair<int, int>> rottenOranges;

    int orangesRotting(vector<vector<int>>& grid) {

        init(grid);
        //initialize a queue of rotten oranges to bfs on
        //and a dictionary of fresh oranges
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == rotten_orange){
                    //queue
                    rottenOranges.push(make_pair(i,j));// y,x coordinates
                } else if (grid[i][j] == fresh_orange) {
                    //fresh
                    fresh_oranges_count++;
                }
                //otherwise empty space
            }
        }

        int minutes = 0;
        if(!fresh_oranges_count){
            return 0;
        }

        while(!rottenOranges.empty()){
            int n = rottenOranges.size();
            for(int i=0;i<n;i++){
                int y=rottenOranges.front().first, x = rottenOranges.front().second;
                rottenOranges.pop();

                //go up
                if(y < top && grid[y+1][x]==fresh_orange){
                    grid[y+1][x] = visited;
                    fresh_oranges_count--;
                    rottenOranges.push(make_pair(y+1,x));
                }
                //go down
                if(y > bottom && grid[y-1][x]==fresh_orange){
                    grid[y-1][x] = visited;
                    fresh_oranges_count--;
                    rottenOranges.push(make_pair(y-1,x));
                }
                //go right
                if(x < right && grid[y][x+1]==fresh_orange){
                    grid[y][x+1] = visited;
                    fresh_oranges_count--;
                    rottenOranges.push(make_pair(y,x+1));
                }
                //go left
                if(x > left && grid[y][x-1]==fresh_orange){
                    grid[y][x-1] = visited;
                    fresh_oranges_count--;
                    rottenOranges.push(make_pair(y,x-1));
                }
            }
            //exit criteria
            minutes++;
            if(!fresh_oranges_count){
                return minutes;
            }
        }
        return -1;
        
    }

    void init(vector<vector<int>>& grid){
        top = grid.size() - 1;
        bottom = 0;
        left = 0;
        right = grid[0].size() - 1;
    }
};
