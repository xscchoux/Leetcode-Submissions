class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> arr(length, 0), diff(length+1, 0);

        for (auto &q:updates) {
            int u = q[0], v = q[1], inc = q[2];
            diff[u] += inc;
            diff[v+1] -= inc;
        }

        int curr = 0;
        for (int i=0; i<length; i++) {
            curr += diff[i];
            arr[i] = curr;
        }

        return arr;
    }
};