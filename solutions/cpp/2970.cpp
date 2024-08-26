class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            for(int j=i; j<nums.size(); j++){
                vector<int> temp;
                for(int k=0; k<i; k++) temp.push_back(nums[k]);
                for(int k=j+1; k<nums.size(); k++) temp.push_back(nums[k]);
                if(isIncreasing(temp)) ans++;
            }
        }
        return ans;
    }

    bool isIncreasing(vector<int> v){
        if(v.size() <= 1) return true;
        for(int i=1; i<v.size(); i++){
            if(v[i] <= v[i-1]) return false;
        }
        return true;
    }
};
