class Solution {
public:
    bool checkPerfectNumber(int num) {
        vector<int> v;
        for(int i=1; i <= num/2; i++){
            if(num % i == 0) v.push_back(i);
        }
        long total = 0;
        for(auto i : v) total += i;
        return num==total;
    }
};