class StockSpanner {
public:
    stack<pair<int,int>> st; // price, index
    StockSpanner() {
        st.push(make_pair(INT_MAX,0));
    }
    
    int next(int price) {
        int cur = st.top().second + 1;
        while(st.top().first <= price){
            st.pop();
        }
        int ans = cur - st.top().second;
        st.push(make_pair(price,cur));
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */