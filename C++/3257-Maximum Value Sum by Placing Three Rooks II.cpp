// https://leetcode.com/problems/maximum-value-sum-by-placing-three-rooks-ii/solutions/5651002/python-solution-o-m-n-top-3-in-row-column-top-11-total/
using TII = tuple<int, int, int>;
using LL = long long;
class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int row = board.size(), col = board[0].size();
        vector<priority_queue<TII, vector<TII>, greater<>>> greatestInCol(col);

        for (int r=0; r<row; r++) {
            priority_queue<TII, vector<TII>, greater<>> pq;
            for (int c=0; c<col; c++) {
                pq.push({board[r][c], r, c});
                if (pq.size() > 3) {
                    pq.pop();
                }
            }
            while (!pq.empty()) {
                auto [val, currR, currC] = pq.top();
                pq.pop();
                greatestInCol[currC].push({val, currR, currC});
                if (greatestInCol[currC].size() > 3) {
                    greatestInCol[currC].pop();
                }
            }
        }

        // get the largest 11 values
        priority_queue<TII, vector<TII>, greater<>> candidates;
        for (int c=0; c<col; c++) {
            while (!greatestInCol[c].empty()) {
                auto [val, currR, currC] = greatestInCol[c].top();
                greatestInCol[c].pop();
                candidates.push({val, currR, currC});
                if (candidates.size() > 11) {
                    candidates.pop();
                }
            }
        }

        vector<TII> arr;
        while (!candidates.empty()) {
            arr.push_back(candidates.top());
            candidates.pop();
        }

        LL res = LLONG_MIN;
        int N = arr.size();
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                for (int k=j+1; k<N; k++) {
                    auto [val1, r1, c1] = arr[i];
                    auto [val2, r2, c2] = arr[j];
                    auto [val3, r3, c3] = arr[k];
                    if (r1!=r2 && r2!=r3 && r1!=r3 && c1!=c2 && c2!=c3 && c1!=c3) {
                        res = max(res, (LL)val1 + val2 + val3);
                    }
                }
            }
        }

        return res;
    }
};