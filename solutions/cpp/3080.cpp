class Solution {
public:

    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        //need to sort by vals then indices
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q; // vals -> indexes
        int n = nums.size(), m = queries.size();
        set<int> marked;
        long long total = 0;
        vector<long long> ans;

        for(int i=0; i<n; i++){
            total+=nums[i];
            q.push({nums[i],i});
        }
        
        for(auto query: queries){
            int index = query[0];
            int removeCount = query[1];
            //query[0]
            if(marked.count(index) == 0){
                total -= nums[index];
                marked.insert(index);
            }
            //query[1]
            while(q.size() && removeCount > 0){
                auto tp = q.top();
                q.pop();
                if(marked.count(tp.second) == 0){
                    total -= tp.first;
                    removeCount--;
                    marked.insert(tp.second);
                }
                if(total < 0) total = 0;
            }
            ans.push_back(total);
        }
        
        return ans;
        
    }
};