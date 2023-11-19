static int fast_io = []() { 
	std::ios::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr); 
	return 0; 
}();

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int> > q;

        for(auto& num : nums){
            if(q.size() != k){
                q.push(num);
            } else {
                if(q.top() < num){
                    q.pop();
                    q.push(num);
                }
            }

        }
        return q.top();

    }
};