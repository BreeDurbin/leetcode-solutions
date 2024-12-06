class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
    unordered_set<int> s;
    for(auto & i : banned){
        s.insert(i);
    }

    int ans = 0, sum = 0;
    for(int i=1; i<=n; i++){
        if(s.find(i) != s.end()) continue;
        if(sum + i > maxSum) break;
        sum += i;
        ans++;
    }

    return ans;
    }
};
