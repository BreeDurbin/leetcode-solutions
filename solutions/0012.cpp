class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> vals{
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, 
            {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"},
            {4, "IV"}, {1, "I"}
            };
        string ans = "";
        for(pair<int, string> val : vals){
            int repeats = num / val.first;
            for(int i=0; i<repeats; i++){
                ans += val.second;
            }
            num %= val.first;
        }
        return ans;
    }
};