class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int, int> freq;
        int n = digits.size();

        for(int i=0; i<n; i++){
            if(digits[i] == 0) continue;
            for(int j=0; j<n; j++){
                if(i == j) continue;
                for(int k=0; k<n; k++){
                    if(k == i || k == j) continue;
                    int cur = 100*digits[i] + 10*digits[j] + digits[k];
                    if(cur & 1) freq[cur]++;
                }
            }
        }

        return freq.size();
    }

};
