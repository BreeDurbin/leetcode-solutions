class NumArray {
public:

    vector<int> tree;
    int n = -1;

    NumArray(vector<int>& nums) : tree(4 * nums.size(), 0) {
        n = nums.size();
        build(1, 0, n - 1, nums);
    }
    
    void update(int index, int val) {
        // i do not know how to pass the correct args to this function
        updateNode(index, val, 1, 0, n - 1);
    }

    void updateNode(int index, int val, int node, int left, int right){
        if(left == right){
            tree[node] = val;
            return;
        }

        int mid = left + (right - left) / 2;

        if(index <= mid){
            updateNode(index, val, 2 * node, left, mid);
        }
        else{
            updateNode(index, val, 2 * node + 1, mid + 1, right);
        }

        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }

    
    int sumRange(int queryLeft, int queryRight) {
        return sumRangeHelper(1, 0, n - 1, queryLeft, queryRight);
    }

    int sumRangeHelper(int node, int currentLeft, int currentRight, int queryLeft, int queryRight){

        if(currentRight < queryLeft || currentLeft > queryRight) return 0; // not inside query at all
        if(currentLeft >= queryLeft && currentRight <= queryRight) return tree[node]; // completely inside query

        // partially inside query so solve each side separately
        int mid = currentLeft + (currentRight - currentLeft) / 2;
        int leftSum = sumRangeHelper(2 * node, currentLeft, mid, queryLeft, queryRight);
        int rightSum = sumRangeHelper(2 * node + 1, mid + 1, currentRight, queryLeft, queryRight);

        return combine(leftSum, rightSum);
    }

    void build(int node, int left, int right, vector<int>& nums){
        if(left == right){
            tree[node] = nums[left];
            return;
        }

        int mid = left + (right - left) / 2;

        build(2 * node, left, mid, nums);
        build(2 * node + 1, mid + 1, right, nums);

        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }

    int combine(int a, int b){ return a + b; }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
