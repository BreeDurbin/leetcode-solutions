class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> reverse_lookup;
        int n = profits.size();
        for(int i=0; i<n; i++){
            reverse_lookup.push_back({capital[i], profits[i]});
        }
        sort(reverse_lookup.begin(), reverse_lookup.end());

        priority_queue<int> q;
        int left = 0;

        for(int i=0; i<k; i++){
            while(left < n && reverse_lookup[left].first <= w){
                q.push(reverse_lookup[left++].second);
            }
            if(q.empty()) break;
            w += q.top();
            q.pop();
        }

        return w;
    }
};
