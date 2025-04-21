class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int curr = 0;
        int mn = 0, mx = 0, diff = upper-lower;
        for (int d:differences) {
            curr += d;
            mn = min(curr, mn);
            mx = max(curr, mx);
            if (upper-lower+1 - (mx-mn) <= 0) return 0;
        }
        
        return upper-lower+1 - (mx-mn);
    }
};