class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans(seq.size());
        int depth = 0;
        for(int i=0; i<seq.size(); i++){
            bool open = seq[i] == '(';
            if(open) depth++;
            ans[i] = depth % 2;
            if(!open) depth--;
        }
        return ans;
    }
};
