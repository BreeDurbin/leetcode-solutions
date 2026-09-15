class Solution {
public:
    int maxPalindromes(string s, int k) {
        if(k == 1) return s.size();

        int n = s.size();

        // we can be greedy because bigged palindromes imply a smaller palindrome is insde the bigger palindrome
        // we want the max number of palindromes so we only check palindromes of size k and k + 1.
        // the reason we need to check size k + 1 also on top of k is to check for the smallest possible of both 
        // odd and even palindromes. 


        int count = 0;
        int i = 0;

        while(i <= n - k){
            if(isPalindrome(s, i, i + k - 1)){
                i += k;
                count++;
            } else if (isPalindrome(s, i, i + k)) {
                i += k + 1;
                count++;
            } else {
                i++;
            }
        }

        return count;
    }

    bool isPalindrome(const string& s, int left, int right){
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }

        return true;
    }
};
