class Solution {
public:
    int countLargestGroup(int n){
        unordered_map<int,int> f, size_to_size_count;
        int biggest_sum = 0;

        for(int i=1; i<=n; i++)f[digit_sum(i)]++;
        for(auto & [k, v] : f) size_to_size_count[v]++;
        for(auto & [k, v] : size_to_size_count) biggest_sum = max(biggest_sum, k);

        return size_to_size_count[biggest_sum];
    }

    int digit_sum(int digit){
        int sum = 0;
        while(digit){
            sum += (digit % 10);
            digit /= 10;
        }
        return sum;
    }
};
