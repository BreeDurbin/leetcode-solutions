class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = closestPalindromeLeft(nums[n/2]);
        int right = closestPalindromeRight(nums[n/2]);
        long long left_cost = 0;
        long long right_cost = 0;
        for(int i=0; i<n; i++){
            left_cost += abs(left - nums[i]);
            right_cost += abs(right - nums[i]);
        }
        return min(left_cost, right_cost);
    }
    
    int closestPalindromeLeft(int num)
    {   
        while (!isPalindrome(num))
            num--;
        return num;
    }

    int closestPalindromeRight(int num)
    {   
        while (!isPalindrome(num))
            num++;
        return num;
    }
    
    bool isPalindrome(int num){
        int temp = num;
        vector<int> split_nums;
        while(temp != 0){
            split_nums.push_back(temp%10);
            temp /= 10;
        }
        int n = split_nums.size();
        for(int i=0; i<n; i++){
            if(split_nums[i] != split_nums[n-i-1]) return false;
        }
        return true;
    }
};