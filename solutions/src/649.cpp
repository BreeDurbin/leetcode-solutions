class Solution {
public:
    queue<int> radiant, dire;

    string predictPartyVictory(string senate) {
      int n = senate.size();
      for(int i=0; i<n; i++){
        if(senate[i] == 'R') radiant.push(i);
        else dire.push(i);
      }

      while(!radiant.empty() && !dire.empty()){
        if(radiant.front() < dire.front()) radiant.push(n++);
        else dire.push(n++);
        radiant.pop(); 
        dire.pop();
      }

      return radiant.empty() ? "Dire" : "Radiant";
    }
};