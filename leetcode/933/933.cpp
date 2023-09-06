static int fast_io = []() { 
	std::ios::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr); 
	return 0; 
}();

class RecentCounter {
    
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int interval = t - 3000;
        q.push(t);
        while(q.top() < interval) q.pop();
        return q.size();
    }
private:
    priority_queue<int, vector<int>, greater<int>>q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */