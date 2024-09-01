class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;
        vector<int> res;
        for (auto &q:queries) {
            pq.push(abs(q[0]) + abs(q[1]));
            if (pq.size() > k) pq.pop();
            res.push_back(pq.size()<k?-1:pq.top());
        }

        return res;
    }
};