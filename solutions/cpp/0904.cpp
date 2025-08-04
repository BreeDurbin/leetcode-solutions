class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n == 0) return 0;

        int ans = 0, cur_max = 0;
        unordered_map<int, int> freq;

        int left = 0;

        for(int right = 0; right < n; right++){
            freq[fruits[right]]++;
            cur_max++;

            while(freq.size() > 2 ){
                int cur_fruit = fruits[left];
                freq[cur_fruit]--;
                cur_max--;
                if(freq[cur_fruit] == 0) freq.erase(cur_fruit);
                left++;
            }

            ans = max(ans, cur_max);
        }


        return ans;
    }
};
