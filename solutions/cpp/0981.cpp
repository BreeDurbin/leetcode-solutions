class TimeMap {
public:

    typedef pair<int, string> bucket;
    unordered_map<string, vector<bucket>> timeMap;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& v = timeMap[key];
        string ret = "";

        int l = 0, r = v.size();
        while(l<r){
            int m = (r+l)/2;
            if(timestamp >= v[m].first){
                l = m + 1;
            }
            else {
                r = m;
            }
        }

        if(r==0) return "";
        return v[r-1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
