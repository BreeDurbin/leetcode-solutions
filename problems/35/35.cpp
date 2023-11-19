class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        std::cout << "Hi" << std::endl;
        return binarySearchRec(nums, target, 0, nums.size()-1);
    }

private: 
  int binarySearchRec(vector<int>& nums, int target, int start, int end){
      int mid = (end+start)/2;
      std::cout << "start: " << start << " end " << end << " mid " << mid << " target " << target << std::endl;

      if(start>end){
          return start;
      }
      else if(nums[mid] < target) {
        std::cout << "Hi LESS THAN compare: " << nums[mid] << " target " << target << std::endl;
        return binarySearchRec(nums, target, mid+1, end);
      }
      else if(nums[mid] > target){
        std::cout << "Hi GREATER THAN " << std::endl;
        return binarySearchRec(nums, target, start, mid-1);
      } 
      else {
        std::cout << "Hi EQUALS " << std::endl;
        return mid;
      }
  }
};