class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prefix(n, INT_MAX), suffix(n, INT_MAX);

        if(arr[0] == target) prefix[0] = 1;
        for(int right = 1, left =  0, sum = arr[0]; right < n; right++){
            sum += arr[right];
            
            while(left < right && sum > target){
                sum -= arr[left];
                left++;
            }

            if(sum == target){
                prefix[right] = min(right - left + 1, prefix[right - 1]);
            } else { prefix[right] = prefix[right - 1]; }
        }

        if(arr[n-1] == target) suffix[n-1] = 1;
        for(int left = n - 2, right = n - 1, sum = arr[n-1]; left >= 0; left--){
            sum += arr[left];
            
            while(right > left && sum > target){
                sum -= arr[right];
                right--;
            }

            if(sum == target){
                suffix[left] = min(right - left + 1, suffix[left + 1]);
            } else { suffix[left] = suffix[left + 1]; }

        }

        int ans = INT_MAX;

        for(int i=1; i<n; i++){
            if(prefix[i-1] != INT_MAX && suffix[i] != INT_MAX){
                ans = min(ans, prefix[i-1] + suffix[i]);
            }
        }


        return ans == INT_MAX ? -1 : ans;
    }
};
