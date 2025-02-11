class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size(), _min = INT_MAX, _max = INT_MIN;
        long long sum = 0;
        for(auto s : salary){
            sum += s;
            _min = min(_min, s);
            _max = max(_max, s);
        }
        return (double)(sum - _min - _max) / (n - 2);
    }
};
