class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        int n=variables.size();
        for(int i=0; i<n; i++){
            if(power(power(variables[i][0], variables[i][1], 10), variables[i][2], variables[i][3]) == target)
                ans.push_back(i);
        }
        return ans;
    }
    
    /* Iterative Function to calculate (x^y)%p in O(log y) */
    int power(long long x, unsigned int y, int p) 
    { 
        int res = 1;     // Initialize result 

        x = x % p; // Update x if it is more than or 
                    // equal to p

        if (x == 0) return 0; // In case x is divisible by p;

        while (y > 0) 
        { 
            // If y is odd, multiply x with result 
            if (y & 1) 
                res = (res*x) % p; 

            // y must be even now 
            y = y>>1; // y = y/2 
            x = (x*x) % p; 
        } 
        return res; 
    } 
};