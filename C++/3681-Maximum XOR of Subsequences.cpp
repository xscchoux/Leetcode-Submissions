// O( NlogN )
// Check XOR basis: https://sam571128.codes/2022/03/29/XOR-Basis/
class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        vector<int> arr(31, 0);

        for (int num:nums) {
            for (int i=30; i>=0; i--) {
                if (num & (1<<i)) {
                    if (arr[i] == 0) {
                        arr[i] = num;
                        break;
                    } else {
                        num = num^arr[i];
                    }
                }
                if (num == 0) break;
            }
        }

        int res = 0;
        for (int i=30; i>=0; i--) {
            res = max(res, res^arr[i]);
        }

        return res;
    }
};