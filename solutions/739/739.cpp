class Solution {
public:
    stack<pair<int,int>> st; // temp, index
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            while(!st.empty() && t[i] > st.top().first){
                pair<int,int> top = st.top();
                st.pop();
                ans[top.second] = i - top.second;
            }
            st.push(make_pair(t[i],i));
        }
        return ans;
    }
};