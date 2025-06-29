using LL = long long;
class Solution {
public:
    int kMod = 1e9+7;
    LL powWithMod(LL a, LL b, int kMod) {
        a %= kMod;
        LL res = 1;

        while(b) {
            if (b&1) res=(res*a)%kMod;
            a=(a*a)%kMod;
            b>>=1;
        }

        return res;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int N = nums.size(), right = N-1;
        long long res = 0;

        for (int i=0; i<N; i++) {
            while (right > i && nums[right]+nums[i] > target) {
                right--;
            }
            if (nums[i] + nums[right] > target) break;
            int count = right-i+1;
            res = (res + powWithMod(2, count-1, kMod))%kMod;
        }

        return res;
    }
};