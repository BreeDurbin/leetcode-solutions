class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int n = s.size(), time = 0;
        long long active_count = 0;

        set<int> indexes = {-1, n};

        while(time < order.size()){
            set<int>::iterator center_it = indexes.insert(order[time]).first;

            int left = *prev(center_it) , right = *next(center_it), center = *center_it;

            active_count += (long long)(center - left) * (right - center);
            
            if(active_count >= k) return time;
            
            time++;
        }

        return -1;
    }
};
