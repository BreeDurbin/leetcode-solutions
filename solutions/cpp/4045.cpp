class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int count = 0;

        for(int right = position.size() - 1; right >= 0;){
            int left = right - 1;
            for(; left >= 0 && (speed[left] > speed[right] || position[left + 1] - position[left] <= distance ); left--){ }
            right = left; 
            count++;
        }

        return count;
    }
};
