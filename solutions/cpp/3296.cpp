class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long total = 0;
        int x = 1, reducedHeight = 0;
        priority_queue<pair<long long ,pair<int, int>>, vector<pair<long long,pair<int, int>>>, greater<>> minHeap;

        for(int i = 0; i< workerTimes.size(); i++){
            minHeap.push({workerTimes[i], {i, 1}});
        }
        
        
        while(mountainHeight){
            auto [ current_time , worker_info ] = minHeap.top();
            minHeap.pop();

            mountainHeight--;
            total = current_time;

            //get worker info
            int workerIndex = worker_info.first;
            int step = worker_info.second;

            //iterate
            ++step;
            long long next_time = current_time + (long long)step * workerTimes[workerIndex];
            minHeap.push({next_time, {workerIndex, step}});
        }
        
        return total;
    }
};
