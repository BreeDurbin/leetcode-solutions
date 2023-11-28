class Solution {
public:

    vector<vector<int>> combinationSum3(int k, int n) {
        if(n>45) return vector<vector<int>>();
        vector<vector<int>> answer;
        vector<int> temp;
        combinationSumRec(1, k, n, answer, temp);
        return answer;
    }

    void combinationSumRec(int start, int k, int n, vector<vector<int>> &answer, vector<int> temp){
        if(temp.size() == k ){
            if(n == 0) {
                answer.push_back(temp);
            } else {
                return;
            }
        }
        for(int i=start; i<=9; i++){
            temp.emplace_back(i);
            combinationSumRec(i+1, k, n-i, answer, temp);
            temp.pop_back();
        }
    }
};