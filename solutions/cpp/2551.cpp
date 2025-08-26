class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();

        long long max_split = 0;
        long long min_split = 0;

        priority_queue<int> maxs;
        priority_queue<int, vector<int>, greater<int>> mins;

        for(int i=1; i<n; i++){
            maxs.push(weights[i-1] + weights[i]);
            mins.push(weights[i-1] + weights[i]);
        }

        for(int i=0; i<k-1; i++){
            max_split += maxs.top();
            maxs.pop();
            min_split += mins.top();
            mins.pop();
        }

        return max_split - min_split;
    }
};
