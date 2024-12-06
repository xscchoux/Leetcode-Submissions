class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int b[10001] = {};
        for (int num:banned) b[num] = 1;
        int cnt = 0, running = 0;
        
        for (int i=1; i<=n; i++) {
            if (b[i] == 1) continue;
            if (running + i > maxSum) break;
            running += i;
            cnt++;
        }

        return cnt;
    }
};