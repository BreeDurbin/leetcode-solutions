class Solution {
public:

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return dfs(nums);
    }

    bool dfs(vector<double>& cards){

        if(cards.size() == 1) return abs(cards[0] - 24.0) <= 1e-8;

        for(int i=0; i<cards.size(); i++){
            for(int j = i + 1; j<cards.size(); j++){
                double a = cards[i];
                double b = cards[j];
                vector<double> next;
                vector<double> possibilities = {a+b, a-b, b-a, a*b, a/b, b/a};
                for(double & num : possibilities){
                    next.clear();
                    next.push_back(num);
                    for(int k = 0; k<cards.size(); k++){
                        if(k != i && k != j) next.push_back(cards[k]);
                    }

                    if(dfs(next)) return true;
                }

            }
        }

        return false;

    }

};
