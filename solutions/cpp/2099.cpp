class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> num_to_index;
        
        //store all nums and their indexes
        for(int i=0; i<nums.size(); i++){
            num_to_index.push_back({nums[i], i});
        }

        //sort based on num size, we will still have their index
        sort(num_to_index.begin(), num_to_index.end(), greater<>());

        vector<pair<int,int>> index_to_num;
        //put the k largest sorted elements with their index in a new table
        for(int i=0; i<k; i++){
            index_to_num.push_back({num_to_index[i].second, num_to_index[i].first});
        }

        //sort the new table based on index, this will reorder the k largest elements to their original order
        sort(index_to_num.begin(), index_to_num.end());

        //put the values into an ans array
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(index_to_num[i].second);
        }

        return ans;
    }
};
