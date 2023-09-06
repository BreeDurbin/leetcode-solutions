static int fast_io = []() { 
	std::ios::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr); 
	return 0; 
}();

class Solution {
public:
    int maxVowels(string s, int k) {
        int maxi = 0;

        for(int i{}; i < k; i++){
            maxi += isVowel(s[i]);
        }

        int curi = maxi;
        //cout << " curi " << curi << " maxi " << maxi << endl;

        int len = s.length();
        for(int i = k; i < len; i++){
            curi += isVowel(s[i]) - isVowel(s[i - k]);
            if (maxi < curi) maxi = max(maxi,curi);
            //cout << " curi " << curi << " maxi " << maxi << endl;
        }
        return maxi;
    }
private:
    int isVowel(char& c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};