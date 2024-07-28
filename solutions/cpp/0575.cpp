class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_map<int, int> candy_count;
        int count = 0;
        
        for(int i=0; i<n; i++){
            candy_count[candyType[i]]++;
            if(candy_count[candyType[i]] == 1) count++;
        }
        
        return min(count, n/2);
        
    }
};