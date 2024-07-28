class Solution {

public:
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);

        // set all nodes to have their own parent;
        for(int i=0; i<n; i++) parent[i] = i;

        //assume all components are unconnected
        //as we find components and compress them 
        // subtract from the number of components
        int components = n;

        for(vector<int> e  : edges){
            int p1 = find(parent, e[0]);
            int p2 = find(parent, e[1]);
            if(p1 != p2) {
                parent[p1] = p2;
                components--;
            }
        }

        return components;
    }

    int find(vector<int> parent, int i ){
        while(i != parent[i]) i = parent[i];
        return i;
    }

};