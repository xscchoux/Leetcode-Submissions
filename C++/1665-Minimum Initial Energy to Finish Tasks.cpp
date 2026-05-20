class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int N = tasks.size();

        // The leftover energy that remains unconsumed after a task is (minimum - actual).
        // In order to maximize the reuse of this "cached energy" for following tasks, 
        // our optimal strategy is to prioritize tasks with the largest difference, 
        // as they leave the maximum amount of energy available.

        sort(begin(tasks), end(tasks), [](auto &a, auto &b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int res = 0, energy = 0;
        for (int i=0; i<N; i++) {
            if (energy < tasks[i][1]) {
                res += tasks[i][1] - energy;
                energy = tasks[i][1];
            }
            energy -= tasks[i][0];
        }

        return res;
    }
};