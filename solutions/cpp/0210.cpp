class Solution {
public:
// topo sort using khuns algorithm
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,list<int>> adj;
        vector<int> ans;
        unordered_map<int,int> indegree; 
        
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        //add all nodes with indegree 0 to queue
        queue<int> q;
        //count indegree
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            //pop off queue and reduce neighbors indegre by 1
            // if any neighbors indegree hit 0 add them to the q
            int node = q.front();
            q.pop();
            ans.push_back(node);

            if(adj.count(node)){
                for(auto neighbor : adj[node]){
                    indegree[neighbor]--;
                    if(indegree[neighbor]==0) q.push(neighbor);
                }
            }
        }

        return numCourses == ans.size() ? ans : vector<int>();
    }
};
