class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int N = numberOfUsers;

        vector<int> res(N, 0);
        vector<bool> online(N, true);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        sort(begin(events), end(events), [&](auto &e1, auto &e2) {
            return stoi(e1[1]) < stoi(e2[1]) || (e1[1] == e2[1] && e1[0] == "OFFLINE");
        });


        for (auto &e:events) {
            int currTime = stoi(e[1]);
            while (!pq.empty() && pq.top().first <= currTime) {
                online[pq.top().second] = true;
                pq.pop();
            }

            if (e[0] == "MESSAGE") {
                if (e[2] == "ALL") {
                    for (int i=0; i<N; i++) {
                        res[i]++;
                    }
                } else if (e[2] == "HERE") {
                    for (int i=0; i<N; i++) {
                        if (online[i]) res[i]++;
                    }                    
                } else {
                    istringstream iss(e[2]);
                    string word;
                    while (iss >> word) {
                        res[stoi(word.substr(2))]++;
                    }
                }
            } else {
                int idNum = stoi(e[2]);
                online[idNum] = false;
                pq.push({currTime+60, idNum});
            }
        }

        return res;
    }
};