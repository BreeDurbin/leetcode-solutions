class NumArray {
public:

    vector<int> cache;

    NumArray(vector<int>& nums) {
        cache.push_back(0);
        cache.insert(cache.end(), nums.begin(), nums.end());

        for(int i=1; i<cache.size(); i++){
            cache[i] += cache[i-1];
        }
        
    }
    
    int sumRange(int left, int right) {
        return cache[right+1] - cache[left];
    }
};
