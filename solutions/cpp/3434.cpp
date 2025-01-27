class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        // freq map
        unordered_map<int, int> freqs;
        for(auto num : nums) freqs[num]++;

        // for each val in freq store 
        int cur_freq = 0, max_freq = 0;

        for(auto & [val,_] : freqs){
            for(auto num : nums){
                //count new num
                if(num == k) cur_freq--;
                if(num == val) cur_freq++;
                //updates running freqs
                if(cur_freq < 0) cur_freq = 0;
                max_freq = max(max_freq, cur_freq);
            }
            cur_freq = 0;
        }

        return freqs[k] + max_freq;
        
    }
};
