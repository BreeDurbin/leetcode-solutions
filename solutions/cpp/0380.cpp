class RandomizedSet {

    private:
    // mapping of values to indexes of the valie in the data array
    unordered_map<int,int> cache;
    //provides indexing which allows us to get O(1) lookups
    vector<int> data;

    public:

    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(cache.find(val) != cache.end()){
            return false;
        }
        data.push_back(val);
        cache[val] = data.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(cache.find(val) == cache.end()){
            return false;
        }
        int cur = cache[val]; // index in data where input val is stored
        int back = data.back();

        cache[back] = cur;
        data[cur] = back;

        data.pop_back();
        cache.erase(val);

        return true;
    }
    
    int getRandom() {
        return data[rand() % data.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */