class Solution {
public:
    vector<int> countBits(int n) {
        int cache[n+1];
        cache[0] = 0;
        vector<int> answer;
        answer.push_back(0);
        int offset=1;
        for(int i=1; i<n+1; i++){
            if(offset*2==i)offset=i;
            cache[i] = 1+cache[i-offset];
            answer.push_back(cache[i]);
        }
        return answer;
    }
};