class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        int ans = 0, m = operations.size();

        for(auto & s : operations){
            int n = scores.size();

            if(s == "+" && n >= 2){
                scores.push_back(scores[n-1] + scores[n-2]);
            }
            else if(s == "D" && n >= 1){
                scores.push_back(2*scores[n - 1]);
            }
            else if(s == "C" && n >= 1){
                scores.pop_back();
            } else {
                scores.push_back(stoi(s));
            }

        }

        for(auto s : scores) ans += s;

        return ans;
    }
};
