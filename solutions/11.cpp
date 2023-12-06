static int fast_io = []() { 
	std::ios::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr); 
	return 0; 
}();

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxh = 0, start = 0, end = height.size() - 1;
        
        while(start<end){
            int h = min(height[start], height[end]);
            maxh = max(maxh, h*(end-start));
            if(height[start] < height[end])start++;
            else if(height[start] > height[end])end--;
            else{
                start++;
                end--;
            }
        }
        return maxh;
    }
};