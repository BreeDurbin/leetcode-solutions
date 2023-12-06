class Solution {
    stack<int> s;
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        for(auto& a : asteroids){
            //push an asteroid onto the stack if it is right noving
            if(a > 0){
                s.push(a);
                continue;
            }
            //collide left moving asteroids with any smaller right moving asteroids in the stack
            while(!s.empty() && s.top() > 0 && abs(a) > s.top()){
                s.pop();
            }
            //If the left moving asteroid is still not exploded stick it on the stack.
            if(s.empty() || s.top() < 0){
                s.push(a);
                continue;
            }
            if(s.top() == abs(a)){
                s.pop();
                continue;
            }
        }

        //vector<int> ans;
        vector<int> ans(s.size());
        while(!s.empty()){
            ans.emplace_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};