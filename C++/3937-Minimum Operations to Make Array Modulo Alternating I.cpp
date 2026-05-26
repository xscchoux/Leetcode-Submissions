class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int N = nums.size();
        int res = INT_MAX;

        for (int x=0; x<k; x++) {
            for (int y=0; y<k; y++) {
                if (x == y) continue;
                int cnt = 0;
                for (int i=0; i<N; i++) {
                    int rem = nums[i]%k;
                    if (i%2 == 0) {
                        cnt += min((rem-x+k)%k, (x-rem+k)%k);
                    } else {
                        cnt += min((rem-y+k)%k, (y-rem+k)%k);
                    }
                }
                res = min(res, cnt);
            }
        }

        return res;
    }
};