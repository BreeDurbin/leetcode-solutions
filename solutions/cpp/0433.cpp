class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        q.push(start);
        unordered_set<string> v;
        int count = 0;

        while(!q.empty()){
            int n = q.size();

            for(int j = 0; j<n; j++){
                string node = q.front();
                q.pop();

                if(node == end) return count;

                for(char c : "ACGT"){
                    for(int i=0; i<node.size(); i++){
                        string neighbor = node;
                        neighbor[i] = c;
                        if(!v.count(neighbor) 
                            && find(bank.begin(), bank.end(), neighbor) != bank.end()){
                            q.push(neighbor);
                            v.insert(neighbor);
                        }
                    }
                }
            }
            count++;
        }

        return -1;
    }
};
