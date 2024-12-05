class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int N = arr.size();
        vector<int> preXOR(N+1, 0);

        for (int i = 0; i<N; i++) {
            preXOR[i+1] = preXOR[i]^arr[i];
        }

        vector<int> res;
        for (auto &q:queries) {
            int u = q[0], v = q[1];
            res.push_back(preXOR[v+1]^preXOR[u]);
        }

        return res;
    }
};

// In-place
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int N = arr.size();

        for (int i = 1; i<N; i++) {
            arr[i] = arr[i-1]^arr[i];
        }

        vector<int> res;
        for (auto &q:queries) {
            if (q[0] == 0) {
                res.push_back(arr[q[1]]);
            } else {
                res.push_back(arr[q[1]]^arr[q[0]-1]);
            }
        }

        return res;
    }
};