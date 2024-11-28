class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - 1;

        while(left <= right){
            int mid = (left + right) / 2;

            if(arr[mid] < x){
                left = mid + 1;
            } else{
                right = mid - 1;
            }
        }

        left--;
        right = left + 1;

        while(right - left - 1  < k){
            if(left == -1){
                right += 1;
                continue;
            }
            if(right == arr.size() || abs(arr[left] - x) <= abs(arr[right] - x)){
                left--;
            } else {
                right++;
            }

        }

        vector<int> ans;
        for(int i = left + 1; i < right; i++){
            ans.push_back(arr[i]);
        }


        return ans;

    }
};
