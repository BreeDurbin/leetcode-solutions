class Solution {
public:

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int m = nums1.size(), n = nums2.size();
        set<pair<int, int>> visited;

        //total,left,right
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> q;
        q.push({nums1[0] + nums2[0], {0, 0}});
        visited.insert({0,0});

        while(k-- && !q.empty()){
            auto t = q.top();
            q.pop();

            int i= t.second.first;
            int j = t.second.second;

            ans.push_back({nums1[i], nums2[j]});

            if(i+1 < m && visited.find({i + 1, j}) == visited.end()){
                q.push({nums1[i+1] + nums2[j],{i+1, j}});
                visited.insert({i+1, j});
            }

            if(j+1 < n && visited.find({i, j + 1}) == visited.end()){
                q.push({nums1[i] + nums2[j + 1],{i, j + 1}});
                visited.insert({i, j + 1});
            }
        }
        
        return ans;
    }
};
