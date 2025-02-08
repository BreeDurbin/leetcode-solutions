class NumberContainers {
public:
    NumberContainers() {
    }

    unordered_map<int, set<int>> mp;// num -> ordered list of indexes with this number
    unordered_map<int, int> reverse_lookup; // index -> number
    
    void change(int index, int number) {
        
        if(reverse_lookup.count(index)){
            int prev_num = reverse_lookup[index];
            mp[prev_num].erase(index);
            if(mp[prev_num].empty()) mp.erase(prev_num);
        }
        
        reverse_lookup[index] = number;
        mp[number].insert(index);
    }
    
    int find(int number) {
        if(!mp.count(number)) return -1;
        return *(mp[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
