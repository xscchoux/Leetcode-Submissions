class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int N = status.size();
        vector<bool> opened(N, false);
        queue<int> q;
        for (int x:initialBoxes) q.push(x);
        
        int res = 0; // candies
        int prev = -1;

        while (!q.empty() && prev != res) {
            prev = res;
            int size = q.size();
            vector<int> cantOpen;
            while (size-- > 0) {
                int curr = q.front();
                q.pop();
                if (status[curr] == 0) {
                    cantOpen.push_back(curr);
                    continue;
                }
                opened[curr] = true;
                for (int k:keys[curr]) {
                    status[k] = 1;
                }
                res += candies[curr];
                for (int b:containedBoxes[curr]) {
                    if (!opened[b]) {
                        q.push(b);
                    }
                }
            }
            for (int i:cantOpen) {
                q.push(i);
            }
        }
        return res;
    }
};