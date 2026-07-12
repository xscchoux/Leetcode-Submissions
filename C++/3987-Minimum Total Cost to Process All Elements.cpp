using LL = long long;
const int kMod = 1e9+7;
class Solution {
public:
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
    int minimumCost(vector<int>& nums, int k) {
        LL op = 0;
        int resource = k;

        for (int num:nums) {
            if (num > resource) {
                int opCnt = (num - resource + k - 1)/k;
                op += opCnt;
                resource = resource + opCnt*k;
            }
            resource -= num;
        }

        return (((op%kMod)*((op+1)%kMod))%kMod)*powWithMod(2, kMod-2, kMod)%kMod;
    }
};