class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        int n = nums.size();
        float average = (float)accumulate(nums.begin(), nums.end(), 0) / (float)n;
        int closest = closestPalindrome(average, nums);
        cout << "closest palendrome: " << closest << " average: " << average << " n: " << n << endl;
        long long cost = 0;
        for(int i=0; i<n; i++){
            cost += abs(closest - nums[i]);
        }
        return cost;
    }
    
    int closestPalindrome(float num, vector<int> nums)
    {
        //IRETATE THROUGH THE ARRAY LOOK AT HOW MANY HIGHER AND HOW MANY lower
        // if higher is higher then we go with ceil
        // if lower is higher then we go with floor
        int higher = 0, lower = 0;
        for(int i=0; i<nums.size(); i++){
            if((float)nums[i] >= num) higher+=nums[i];
            else lower+=nums[i];
        }
        // handle ceil and floor of num beign a palendrome
        if(higher > lower && isPalindrome(ceil(num))) return ceil(num);
        else if(lower > higher && isPalindrome(floor(num))) return floor(num);

        
        int low = num - 1;
        while (!isPalindrome(low))
            low--;
        int high = num + 1;
        while (!isPalindrome(high))
            high++;
        if (abs(num - low) > abs(num - high))
            return high;
        else
            return low;
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