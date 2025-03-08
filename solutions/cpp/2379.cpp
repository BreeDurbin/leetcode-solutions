class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX, w_cnt = 0, left = 0, right = 0, m = blocks.size();

        while(right < m){
            //expand out to the right until the windows size is k
            while(right < m && right - left < k){
                if(blocks[right] == 'W') w_cnt++;
                right++;
            }
            ans = min(ans, w_cnt);
            if(blocks[left] == 'W') w_cnt--; // collapse the left in one index, decrementing white count if a W gets removed
            left++; 
        }

        return ans;
    }
};
