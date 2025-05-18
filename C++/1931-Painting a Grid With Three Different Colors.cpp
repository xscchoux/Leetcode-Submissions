static constexpr int kMod = 1e9+7;
class Solution {
private:
    bool check(int pre, int curr, int m) {
        while (m-- > 0) {
            if (pre%3 == curr%3) {
                return false;
            }
            pre /= 3;
            curr /= 3;
        }

        return true;
    }
public:
    int colorTheGrid(int m, int n) {
        vector<int> valid;
        int tot = pow(3, m);
        for (int num=0; num<tot; num++) {
            vector<int> pos(m);
            int tmp = num;
            for (int i=0; i<m; i++) {
                pos[i] = tmp%3;
                tmp /= 3;
            }

            bool isValid = true;
            for (int i=1; i<m; i++) {
                if (pos[i-1] == pos[i]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                valid.push_back(num);
            }
        }

        vector<int> dp(tot, 0);
        for (int val:valid) dp[val] = 1;

        for (int c=1; c<n; c++) {
            vector<int> nxt(tot, 0);
            for (int currVal:valid) {
                for (int preVal:valid) {
                    if (check(preVal, currVal, m)) { 
                        nxt[currVal] = (nxt[currVal] + dp[preVal])%kMod;   
                    }
                }
            }
            dp = nxt;
        }

        int res = 0;
        for (int num:dp) {
            res = (res + num)%kMod;
        }

        return res;
    }
};


// Faster if we use an adjacent matrix
class Solution {
private:
    static constexpr int kMod = 1e9+7;
    bool check(int pre, int curr, int m) {
        while (m-- > 0) {
            if (pre%3 == curr%3) {
                return false;
            }
            pre /= 3;
            curr /= 3;
        }

        return true;
    }
public:
    int colorTheGrid(int m, int n) {
        vector<int> valid;
        int tot = pow(3, m);
        for (int num=0; num<tot; num++) {
            vector<int> pos(m);
            int tmp = num;
            for (int i=0; i<m; i++) {
                pos[i] = tmp%3;
                tmp /= 3;
            }

            bool isValid = true;
            for (int i=1; i<m; i++) {
                if (pos[i-1] == pos[i]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                valid.push_back(num);
            }
        }

        vector<int> dp(tot, 0);
        for (int val:valid) dp[val] = 1;

        vector<vector<int>> adj(tot);
        for (int currVal:valid) {
            for (int nxtVal:valid) {
                if (check(currVal, nxtVal, m)) {
                    adj[currVal].push_back(nxtVal);
                }
            }
        }

        for (int c=1; c<n; c++) {
            vector<int> nxt(tot, 0);
            for (int currVal:valid) {
                for (int preVal:adj[currVal]) {
                    nxt[currVal] = (nxt[currVal] + dp[preVal])%kMod;
                }
            }
            dp = nxt;
        }

        int res = 0;
        for (int num:dp) {
            res = (res + num)%kMod;
        }

        return res;
    }
};