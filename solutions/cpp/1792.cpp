class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        auto computeGain = [](int passes, int students){
            return (double)(passes+1)/(students+1) - (double) passes/students;
        };

        priority_queue<pair<double, pair<int,int>>> q;

        for(auto & clazz : classes){
            q.push({computeGain(clazz[0], clazz[1]), {clazz[0], clazz[1]}});
        }


        while(extraStudents--){
            auto [gain, clazz] = q.top();
            q.pop();
            q.push({computeGain(clazz.first + 1, clazz.second + 1), {clazz.first + 1, clazz.second + 1}});
        }

        double sum = 0;

        while(!q.empty()){
            auto[gain, clazz] = q.top();
            q.pop();
            sum += (double)clazz.first / clazz.second;
        }

        return sum/classes.size();


    }
};
