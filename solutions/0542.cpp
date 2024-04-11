
class Solution {
public:
    
    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<vector<int>> q; // {x,y,dist}

        for(int i=0; i< m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({i,j,0});
                } else {
                    mat[i][j] = -1;
                }
            }
        }

        while(!q.empty()){
            for(int i=0; i<q.size(); i++){
                auto temp = q.front();
                q.pop();

                for(auto dir : dirs){
                    int dx = temp[0] + dir.first, dy = temp[1] + dir.second, ddist = temp[2] + 1;
                    if(dx < 0 || dx >= m || dy < 0 || dy >= n || mat[dx][dy] != -1) continue;
                    mat[dx][dy] = ddist; 
                    q.push({dx,dy,ddist});
                }

            }
        }

        return mat;
    }
};