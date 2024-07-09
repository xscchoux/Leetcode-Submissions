class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double tot = 0;
        int N = customers.size();

        int endTime = 0;
        for (auto &c:customers) {
            int u = c[0], v = c[1];
            endTime = max(endTime, u);
            endTime += v;
            tot += endTime - u;
        }

        return tot/N;
    }
};