class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans = 0;
        for(auto num : derived){
            ans ^= num;
        }
        return ans == 0;
    }
};
