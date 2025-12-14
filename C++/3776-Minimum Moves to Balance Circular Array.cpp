// First AC, very lengthy
class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int negIdx = -1;
        
        for (int i=0; i<balance.size(); i++) {
            if (balance[i] < 0) {
                negIdx = i;
            }
        }
        if (negIdx == -1) return 0;

        int N = balance.size();

        vector<bool> visited(N, false);
        visited[negIdx] = true;

        int step = 1, negVal = balance[negIdx];
        long long res = 0;

        while (true) {
            int idx1 = (negIdx+step+N)%N, idx2 = (negIdx-step+N)%N;
            if (visited[idx1] && visited[idx2]) break;
            auto [mn, mx] = minmax(balance[idx1], balance[idx2]);
            if (balance[idx1] < balance[idx2]) {
                swap(idx1, idx2);
            }
            if (negVal + mx >= 0) {
                res += -1LL*negVal*step;
                negVal = 0;
                break;
            }
            negVal += mx;
            res += mx*step;
            visited[idx1] = true;

            if (idx1 == idx2) break;

            if (negVal + mn >= 0) {
                res += -1LL*negVal*step;
                negVal = 0;
                break;
            }
            negVal += mn;
            res += mn*step;
            visited[idx2] = true;

            step++;
        }

        if (negVal < 0) return -1;

        return res;
    }
};



// More concise. Borrow the idea from lee215
// https://leetcode.com/problems/minimum-moves-to-balance-circular-array/solutions/7412202/javacpython-on-by-lee215-n5tx/
class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int negIdx = -1;

        for (int i=0; i<balance.size(); i++) {
            if (balance[i] < 0) {
                negIdx = i;
            }
        }

        if (negIdx == -1) return 0;

        long long tot = accumulate(begin(balance), end(balance), 0LL);
        if (tot < 0) return -1;

        int N = balance.size(), step = 1, negVal = balance[negIdx];
        long long res = 0;

        while (negVal < 0) {
            int idx1 = (negIdx+step+N)%N, idx2 = (negIdx-step+N)%N;

            long long storage = balance[idx1] + balance[idx2];
            res += min(-1LL*negVal, storage)*step;
            negVal += storage;
            step++;
        }

        return res;
    }
};