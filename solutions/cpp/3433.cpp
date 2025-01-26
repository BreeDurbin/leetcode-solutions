class Solution {


public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {

        //map events to be less retarded
        int n = events.size();

        sort(events.begin(), events.end(), [&](const auto& e1, const auto& e2) {
            if(e1[1] != e2[1]) return stoi(e1[1]) < stoi(e2[1]);
            return e1[0][0] > e2[0][0];
        });

        vector<int> mentions(numberOfUsers);
        vector<long long> expiration_times(numberOfUsers);
        
        int i = 0;
        for(auto event : events){
            string eventType = event[0], idString = event[2]; 
            int timestamp = stoi(event[1]);
            
            if(eventType == "MESSAGE"){

                vector<string> users = split(idString);
                for(auto user : users){
                    if(user.substr(0, 2) == "id"){
                        int id = stoi(user.substr(2, user.size() - 2));
                        mentions[id]++;
                    } else if (user == "HERE"){
                        for(int i=0; i<numberOfUsers; i++){ 
                            if(timestamp >= expiration_times[i]){
                                mentions[i]++;
                            }
                        }
                    } else {
                        for(int i=0; i<numberOfUsers; i++) mentions[i]++;
                    }
                }
            } else {
                expiration_times[stoi(idString)] = timestamp + 60;
            }
        }
        return mentions;
    }

    vector<string> split(string userString){
        stringstream ss(userString);
        vector<string> ans;
        string token;

        while(getline(ss, token, ' ')) if(!token.empty()) ans.push_back(token);

        return ans;
    }

};
