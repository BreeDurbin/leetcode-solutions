class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater());
        int ans = 0, n = citations.size();
        for(int i=0; i<n; i++){
            if(citations[i] >= i + 1){
                ans++;
            } else break;
        }
        return ans;
    }
};