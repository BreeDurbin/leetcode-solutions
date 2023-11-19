class Solution {
public:

    queue<pair<int, int>> q;
    int bottom, left, top, right;
    char valid_square = '.', visited = 'x';

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        init(maze);
        q.push(make_pair(entrance[0], entrance[1]));

        int k = 0;
        maze[entrance[0]][entrance[1]] = visited;

        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                int y=q.front().first, x = q.front().second;
                q.pop();

                //go up
                if(y < top && maze[y+1][x]==valid_square){
                    maze[y+1][x] = visited;
                    q.push(make_pair(y+1,x));
                }
                //go down
                if(y > bottom && maze[y-1][x]==valid_square){
                    maze[y-1][x] = visited;
                    q.push(make_pair(y-1,x));
                }
                //go right
                if(x < right && maze[y][x+1]==valid_square){
                    maze[y][x+1] = visited;
                    q.push(make_pair(y,x+1));
                }
                //go left
                if(x > left && maze[y][x-1]==valid_square){
                    maze[y][x-1] = visited;
                    q.push(make_pair(y,x-1));
                }

                //exit criteria
                if(!(y == entrance[0] && x == entrance[1]) 
                    && (x==left || y==top || x==right or y==bottom)){
                    return k;
                }
            }
            k++;
        }
        return -1;
    }

    void init(vector<vector<char>>& maze){
        top = maze.size() - 1;
        bottom = 0;
        left = 0;
        right = maze[0].size() - 1;
    }
};