class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<bool> vis(numCourses);
        vector<bool> ancestor(numCourses);


        // create adj list 
        for(auto& prerequisite : prerequisites){
            adj[prerequisite[1]].push_back(prerequisite[0]);
        }

        // dfs on all nodes in graph dfs will only be called for each component of the graph
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(dfs_is_cycle(i, adj, ancestor, vis)) return false;
            }
        }

        return true;

    }

    // returns true if a cycle was found
    bool dfs_is_cycle(int node, vector<vector<int>>& adj, vector<bool>& ancestor, vector<bool>& vis){
        if(ancestor[node]) return true; // back edge
        if(vis[node]) return false; // no back edge but heve already been here on a diff dfs
        ancestor[node] = true;
        vis[node] = true;

        for(int child : adj[node]){
            if(dfs_is_cycle(child, adj, ancestor, vis)) return true;
        }
        ancestor[node] = false;

        return false;
    }
};
