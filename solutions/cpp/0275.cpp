class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0, right = citations.size() - 1, n = citations.size();

        while (left <= right){
            int mid = (left + right) / 2;
            int papers = n - mid;

            if(citations[mid] == papers) return citations[mid];
            else if(citations[mid] < papers){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return n - left;
    }
};
