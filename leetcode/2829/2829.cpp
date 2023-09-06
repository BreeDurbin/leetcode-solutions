class Solution {
public:
    int minimumSum(int n, int k) {
        
        int ans = 0;
        int ans_size = 0;
        
        //we want to find the maximum number of integers from n = 1 to n = k - 1 
        // such that no two ints sum to k;
        int half_k = k / 2;
        for(int i = 1; i <= half_k; i++){
            if(ans_size == n) break;
            cout << "i: " << i << endl;
            ans += i;
            ans_size++;
        }
        
        // if n > k then we fill with k, k + 1, k + 2 .. n
        if(n >= half_k){
            int j = 0;
            for(int i = ans_size; i < n; i++){
                cout << "i: " << k + j << endl;
                ans += k + j;
                j++;
            }
        }

        return ans;
    }
};