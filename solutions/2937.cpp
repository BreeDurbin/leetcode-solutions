class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        //cout << "s1" << s1[0] << "s2" << s2[0] << "s3" << s3[0] << endl; 
        if(s1[0] != s2[0] || s1[0] != s3[0]){
            //cout << "HI" << endl; 
            return -1;
        } 
        int sameness = 1;
        
        for(int i=1; i<s1.size(); i++){
            if(s1[i] != s2[i] || s1[i] != s3[i]) break;
            sameness++;
        }
        
        //cout << "SAMENESS: " << sameness << endl;
        
        
        return (s1.size() + s2.size() + s3.size()) - 3*sameness; 
    }
};