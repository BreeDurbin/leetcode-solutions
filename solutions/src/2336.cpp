class SmallestInfiniteSet {
public:

    //Using weak ordering from c++ set.
    // set has ordering from 1-1000 in order because we build it that way in the constructor.
    set<int> s;
    SmallestInfiniteSet() {
        for(int i=1; i<=1000;i++){
            s.insert(i);
        }
    }
    
    int popSmallest() {
        auto i = s.begin();
        int ans = *i;
        s.erase(i);
        return ans;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */