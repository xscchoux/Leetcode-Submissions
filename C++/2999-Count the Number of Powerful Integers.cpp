using LL = long long;
class Solution {
public:
    // https://www.youtube.com/watch?v=T94ukar9SZM
    // digit counting
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        bool prefix_same = true;
        int ind = 0;
        string end1 = to_string(finish), end2 = to_string(start-1); 
        return ((end1.size() < s.size())?0:dfs(end1, limit, s, ind, prefix_same)) - (end2.size() < s.size()?0:dfs(end2, limit, s, ind, prefix_same));
    }
    
    LL dfs(string currNum, int limit, string s, int ind, bool prefix_same) {
        if (ind == currNum.size() - s.size()) {
            if ( !prefix_same || currNum.substr(ind) >= s ) return 1;
            else return 0;
        }
        LL res = 0;
        if (!prefix_same) {
            int change = currNum.size() - s.size() - ind;
            res += pow(limit+1, change);
        } else {
            for (int i=0; i<=limit; i++) {
                if (i > currNum[ind]-'0') break;
                else if (i == currNum[ind]-'0') res += dfs(currNum, limit, s, ind+1, true);
                else res += dfs(currNum, limit, s, ind+1, false);
            }
        }
        return res;
    }
};

// digit DP
using LL = long long;
class Solution {
public:
    string suffix;
    int limit, N;
    LL dp[16][2];
    long long count(int idx, string& largest, int upper) {  // upper == 1: reach limit
        if (largest.size() < suffix.size()) {
            return 0;
        }
        if (idx == largest.size() - suffix.size()) {
            if (upper == 1) {
                if (stol(suffix) > stol(largest.substr(idx)) ) {
                    return 0;
                } else {
                    return 1;
                }
            }
            return 1;
        }

        if (dp[idx][upper] != -1) return dp[idx][upper];

        LL tot = 0;
        if (upper == 1) {
            tot += (min(limit, largest[idx] - '0'))*count(idx+1, largest, 0);
            if (limit >= largest[idx]-'0') {
                tot += count(idx+1, largest, 1);
            } else {
                tot += count(idx+1, largest, 0);
            }
        } else {
            tot += count(idx+1, largest, 0)*(limit+1);
        }

        return dp[idx][upper] = tot;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        this->suffix = s;
        this->limit = limit;
        N = s.size();
        memset(dp, -1, sizeof(dp));
        string startString = to_string(start-1), finishString = to_string(finish); 
        LL upper = count(0, finishString, 1);
        memset(dp, -1, sizeof(dp));
        LL lower = count(0, startString, 1);

        return upper-lower;
    }
};