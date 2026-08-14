class Solution {
public:
    bool isOK(long long mid, vector<int>& monsters, vector<long long>& diff) {
        long long strength = mid, bonus = 0;

        for (int i=0; i<monsters.size(); i++) {
            bonus += diff[i];
            if (strength + bonus < monsters[i]) {
                return false;
            }
            strength = max(0LL, strength - monsters[i]);
        }

        return true;
    }
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int N = monsters.size();
        vector<long long> diff(N, 0);

        for (auto &b:boosts) {
            int u = b[0], v = b[1], w = b[2];
            diff[u] += w;
            if (v + 1 < N) {
                diff[v+1] -= w;
            }
        }   

        long long left = 0, right = accumulate(begin(monsters), end(monsters), 0LL);

        while (left + 1 < right) {
            long long mid = left + (right-left)/2;
            if (isOK(mid, monsters, diff)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (isOK(left, monsters, diff)) {
            return left;
        }
        
        return right;
    }
};



// really clever O(n) solution from Lee
// https://leetcode.com/problems/minimum-initial-strength-to-defeat-all-monsters/solutions/8434996/javacpython-backward-by-lee215-1vs7/
class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int N = monsters.size();
        vector<long long> diff(N, 0);
        for (auto &b:boosts) {
            int u = b[0], v = b[1], w = b[2];
            diff[v] += w;
            if (u-1 >= 0) diff[u-1] -= w;
        }

        long long bonus = 0, strength = 0;  // the final strength is 0 after defeating all the monsters

        for (int i=N-1; i>=0; i--) {
            bonus += diff[i];
            if (strength > 0) {
                strength += monsters[i];
            } else {   // previous strength is decreased to 0 by monsters[i] (if it becomes negative, it is set to 0)
                strength = max(0LL, (long long)monsters[i] - bonus);
            }
        }

        return strength;
    }
};