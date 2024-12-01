class Solution {
public:
    bool checkIfExist(vector<int>& nums) {
        unordered_map<int, bool> m;

        for(int num : nums){
            if(num % 2 == 0 &&  m.find(num / 2) != m.end()) return true;
            if(m.find(2 * num) != m.end()) return true;
            m[num] = true;
        }

        return false;
    }
};
