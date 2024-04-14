class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int first = -1, second = -1;
        bool flag = false;
        for(int i=0; i<nums.size(); i++){
            bool prime = isPrime(nums[i]);
            if(!flag && prime){
                first = i;
                second = i;
                flag = true;
            }
            else if(flag && prime) second = i;
        }
        return second - first;
        
    }
    
    bool isPrime(int n)
    {
        if (n <= 1) return false;

        for (int i = 2; i <= n / 2; i++)
            if (n % i == 0) return false;
        return true;
    }
};