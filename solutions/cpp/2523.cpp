class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> left(n), right(n);

        //init left and right arrays
        for(int i=0; i<n; i++){
            while(st.size() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            left[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }
        st = stack<int>();
        for(int i=n-1; i>=0; i--){
            while(st.size() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            right[i] = st.empty() ? n-1 : st.top() - 1;
            st.push(i);
        }


        int max_size = 0;
        for(int i=0; i<n; i++){
            max_size = max(max_size, heights[i] * (right[i] - left[i] + 1));
        }

        return max_size;
    }
};
