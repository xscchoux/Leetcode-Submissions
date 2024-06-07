class Solution {
public:
    vector<int> maxHammingDistances(vector<int>& nums, int m) {
        queue<int> q;
        vector<int> dist((1<<m)+1, -1);

        for (int num:nums) {
            q.push(num);
            dist[num] = 0;
        }

        while (!q.empty()) {
            int length = q.size();
            while (length-- > 0) {
                int curr = q.front();
                q.pop();
                for (int i=0; i<m; i++) {
                    int nxt = curr^(1<<i);
                    if (dist[nxt] == -1) {
                        dist[nxt] = dist[curr] + 1;
                        q.push(nxt);
                    }
                }
            }
        }

        vector<int> res;

        for (int num:nums) {
            int complement = num^((1<<m)-1);
            res.push_back(m-dist[complement]);
        }

        return res;
    }
};