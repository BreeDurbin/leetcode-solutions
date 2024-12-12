class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
    long long ans = 0;
    priority_queue<int> q;
    for(auto g : gifts){
        q.push(g);
    }

    while(k--){
        int t = q.top();
        q.pop();
        q.push(floor(sqrt(t)));
    }

    while(!q.empty()){
        ans += q.top();
        q.pop();
    }

    return ans;
    
    }
};
