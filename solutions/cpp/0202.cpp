class Solution {
public:
    unordered_map<int, bool> visited;
    bool isHappy(int n) {
        int happier = n;
        while(n != 1 && !visited[n]){
            int temp = happier;
            vector<int> split_nums;
            while(temp != 0){
                split_nums.push_back(temp%10);
                temp /= 10;
            }
            int next = 0;
            for(int num : split_nums){
                next += num*num;
            }
            happier = next;
            if(!visited[happier]) visited[happier] = true;
            else break;
        }
        return happier != 1 ? false : true;
    }
};