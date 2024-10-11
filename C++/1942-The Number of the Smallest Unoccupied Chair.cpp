class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int mx = 0, N = times.size();
        int target = times[targetFriend][0];

        sort(times.begin(), times.end());

        priority_queue<int, vector<int>, greater<>> available;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> used;   // {end time, index of chair}   
        for (int i=0; i<N; i++) available.push(i);

        unordered_map<int, int> res;
        for (auto t:times) {
            while (!used.empty() && t[0] >=used.top().first) {
                auto [time, idx] = used.top();
                used.pop();
                available.push(idx);
            }

            int sitted = available.top();
            if (target == t[0]) return sitted;
            available.pop();
            used.push({t[1], sitted});
        }

        return -1;
    }
};