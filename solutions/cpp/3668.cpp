class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n = order.size();
        unordered_map<int,int> id_to_order;
        for(int i=0; i<n; i++){
            id_to_order[order[i]] = i;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i=0; i<friends.size(); i++){
            int friend_id = friends[i];
            pq.push({id_to_order[friend_id], friend_id});
        }

        vector<int> ans{};
        ans.reserve(friends.size());

        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
