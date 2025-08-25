class  Solution{
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> vis(n, false);
        unordered_map<int, vector<int>> teleports; // vals to nodes with the val

        for(int i=0; i<n; i++){
            teleports[arr[i]].push_back(i);
        }

        int steps = 0;
        queue<int> q;
        q.emplace(0);
        vis[0] = true;

        while(q.size()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int node = q.front();
                q.pop();
                if(node == n - 1) return steps;

                if(node + 1 < n && ! vis[node+1]) q.push(node + 1);
                if(node - 1 >= 0 && ! vis[node-1]) q.push(node - 1);
                for(int target : teleports[arr[node]]){
                    if(vis[target]) continue;
                    vis[target] = true;
                    q.push(target);
                }
                // prevent tle from edge case where there are a ton of indexes with the same value;(pure evil)
                teleports[arr[node]].clear(); 
            }
            steps++;
        }

        return steps;
    }

};
