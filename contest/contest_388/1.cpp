class Solution {
public:
    int minimumBoxes(vector<int>& apples, vector<int>& capacity) {
        int m = apples.size(), n = capacity.size(), apples_count = 0, ans = 0;
        priority_queue<int> maxHeap;
        
        for(auto& a : apples) apples_count += a;
        for(auto& c : capacity) maxHeap.push(c);
        
        while(maxHeap.size() > 0 && apples_count > 0){
            apples_count -= maxHeap.top();
            maxHeap.pop();
            ans++;
        }
        
        return ans;
        
    }
};