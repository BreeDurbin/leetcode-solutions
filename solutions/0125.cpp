class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;
        while(start < end){
            if(!isalnum(s[start])){ 
                start++;
                continue;
            }
            if(!isalnum(s[end])){ 
                end--;
                continue;
            }
            //std::cout << "start " << s[start] << " end " << s[end] << std::endl;
            if(tolower(s[start]) != tolower(s[end])) return false;
            start++;
            end--;
        }
        return true;
    }
};