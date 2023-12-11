class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), total=0;
        vector<int> left(n), right(n);

        //initialize first element of prefix/suffix max arrays
        left[0] = height[0];
        right[n-1] = height[n-1];

        //initialize prefix max and suffix max arrays.
        for(int i=1; i<n; i++){
            left[i] = max(height[i], left[i-1]);
        }
        for(int i=n-2; i>=0; i--){
            right[i] = max(height[i], right[i+1]);
        }

        //sum the total
        for(int i=0; i<n; i++){
            total += abs(min(left[i], right[i]) - height[i]);
        }

        return total;
    }
};