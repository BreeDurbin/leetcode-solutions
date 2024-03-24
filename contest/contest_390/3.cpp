class Solution {

typedef pair<int, int> pd;
 
// Structure of the condition
// for sorting the pair by its
// second elements
struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        return a.second < b.second;
    }
};
    
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        //ans of length n, where ans[i] represents the count of the most frequent ID in the collection after the ith step
        vector<long long> ans(n);
        //heap of pairs with type pair<int id, int freq>;
        priority_queue<pd, vector<pd>, myComp> id_freq_heap;
        unordered_map<int, long long> id_freq_map;
        
        for(int i=0; i<n; i++){
            if(freq[i] > 0){
                id_freq_map[nums[i]] += freq[i];
                //do heap stuffs
                id_freq_heap.push({nums[i], id_freq_map[nums[i]]});
            } else {
                id_freq_map[nums[i]] -= freq[i];
                // do heap stuffs
                // if the top of the heap is no longer biggest pop it
                pair<int, int> id_freq_pair = id_freq_heap.top();
                id_freq_heap.pop();
                if(id_freq_pair.second > id_freq_heap.top().second) id_freq_heap.push(id_freq_pair);
            }
            //populate ans[i]
            ans[i] = id_freq_heap.top().second;
        }
        
        
        return ans;
    }
};