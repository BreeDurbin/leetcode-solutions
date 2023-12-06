#include<string>

class Solution {
public:
    int romanToInt(string s) {
        int total = 0;
        for(int i = 0; i < s.size(); i++){

            if(i < s.size()){
                auto ebil_val = std::string() + s[i] + s[i + 1];
                if(ebil_vals.count(ebil_val)){
                    total += ebil_vals[ebil_val];
                    i++;
                    continue;
                }
            }

            total += values[s[i]];
        }
        return total;
    }

private: 
    unordered_map<char, int> values = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
    unordered_map<std::string, int> ebil_vals = {{"IV",4}, {"IX",9}, {"XL",40}, {"XC",90}, {"CD",400}, {"CM",900}};
};