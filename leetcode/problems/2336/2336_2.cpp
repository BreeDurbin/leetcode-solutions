class SmallestInfiniteSet {
public:
    int index=0;
    int dp[1000];

    SmallestInfiniteSet() {
    }
    
    int popSmallest() {
        int s=index;
        dp[s] = 1;
        while(dp[index]==1) index++;
        return s+1;
    }
    
    void addBack(int num) {
        dp[num-1]=0;
        if(index>num-1){
            index=num-1;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */