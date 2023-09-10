class Solution {
public:
    ///Brute force O(n^2)
    /*int countPairs(vector<int>& nums, int target) {
        int n = nums.size(), count=0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n;j++){
                if(nums[i]+nums[j]<target) count++;
            }
        }
        return count;
    }*/

    //Two pairs, O(nlogn)
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int start=0,end=nums.size()-1, count=0;;
        while(start<end){
            if(nums[start]+nums[end]<target){
                cout << "start: " << start << " end " << end << endl;
                count += end-start;
                start++;
            }
            else end--;
        }
        return count;
    }
};