class Solution {
public:
    int strStr(string haystack, string needle) {

        for(int i = 0; i < haystack.size(); i++){
            if(haystack[i] == needle[0]){
                for(int samenessCount=1; samenessCount<=needle.size(); samenessCount++){
                    std::cout << " i: " << i << " samenessCount: " << samenessCount << std::endl;
                    if(samenessCount == needle.size()){
                        std::cout<< " returning int: " << i << std::endl;
                        return i;
                    } else if(haystack[i+samenessCount] != needle[samenessCount]){
                        std::cout<< "breaking: " << haystack[i+samenessCount] << "!=" << needle[samenessCount] << std::endl;
                        samenessCount = needle.size() - 1;
                        break;
                    } 
                }
            }
        }
        return -1;
    }
};