class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        vector<int> substrings[26];
        int count = -1;

        int letterPos = 0;
        int letterCount = 1;
        
        if(s[0] != s[1]){
            substrings[s[0] - 'a'].push_back(1);
        }
        
        for(int i=1; i<n; i++){
            if(s[i] == s[letterPos]){
                letterCount++;
                //cout << "letterCount" << letterCount << endl;
                if(i == n-1) substrings[s[i] - 'a'].push_back(i+1-letterPos);
            }
            else{
                substrings[s[i] - 'a'].push_back(i+1-letterPos);
                letterCount = 1;
                letterPos = i;
            }
        }
        
        for(int letter=0; letter<26; letter++){
            if(substrings[letter].size() == 0) continue;
            sort(substrings[letter].begin(), substrings[letter].end());
            cout << "letter " << letter << " size " << substrings[letter][0] << endl;
            //find the max of each sorted array
            int tempMax = -1;
            if(substrings[letter][0] >= 3){
                tempMax = max(tempMax, substrings[letter][0] - 2);
            }
            if(substrings[letter].size() >= 2){
                if(substrings[letter][0] > substrings[letter][1]){
                    tempMax = max(tempMax, substrings[letter][1]);
                } else {
                    tempMax = max(tempMax, substrings[letter][1] - 1);
                }
            }
            if(substrings[letter].size() >= 3){
                tempMax = max(tempMax, substrings[letter][2]);
            }
            
            count = max(count, tempMax);
        }
        
        return count;
    }
    
    
};