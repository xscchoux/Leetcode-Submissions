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