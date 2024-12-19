class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0, curMax = 0;

        for(int i = 0; i < arr.size(); i++){
            curMax = max(curMax, arr[i]);
            if(curMax == i) chunks++;
        }


        return chunks;
        
    }
};
