class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {

        long long ans = 0;
        int m_div_4_div_2 = pizzas.size()/4;
        priority_queue<int> q;

        for(auto p : pizzas){
            q.push(p);
        }

        for(int i=1; i<=m_div_4_div_2; i++) if(i%2==1){ ans += q.top(); q.pop(); }
        for(int i=2; i<=m_div_4_div_2; i++) if(i%2==0){ q.pop(); ans += q.top(); q.pop(); }
        
        return ans;
    }
};
