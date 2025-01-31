class Solution {
public:
    int strStr(string haystack, string needle) {

        for(int i = 0; i < haystack.size(); i++){
            if(haystack[i] == needle[0]){
                for(int samenessCount=1; samenessCount<=needle.size(); samenessCount++){
                    if(samenessCount == needle.size()){
                        return i;
                    } else if(haystack[i+samenessCount] != needle[samenessCount]){
                        samenessCount = needle.size() - 1;
                        break;
                    } 
                }
            }
        }
        return -1;
    }
};
