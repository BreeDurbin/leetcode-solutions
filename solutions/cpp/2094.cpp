class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        unordered_map<int,int> dict;

        for(int d : digits){
            dict[d]++;
        }

        for(int i=100; i<1000; i++){
            if(i%2 == 1) continue;
            bool flag = true;
            unordered_map<int, int> nums;
            int temp = i;
            for(int j=0; j<3; j++){
                nums[temp%10]++;
                temp/=10;
            }
            for(auto & [ key, value] : nums){
                if( dict[key] < value) flag = false;
            }
            if(flag){
                ans.push_back(i);
            }
        }
        
        return ans;
    }

};
