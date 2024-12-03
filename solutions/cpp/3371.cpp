
class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int outlier = INT_MIN, sum = 0;
        unordered_map<int,int> m;

        for(auto num : nums){
            m[num]++;
            sum += num;
        }

        for(auto num : nums){
            int potentialOutlier = sum - num - num;
            if(m[potentialOutlier] > (potentialOutlier == num)){
                outlier = max(potentialOutlier, outlier);
            }
        }

        return outlier == INT_MIN ? -1 : outlier;
    }
};
