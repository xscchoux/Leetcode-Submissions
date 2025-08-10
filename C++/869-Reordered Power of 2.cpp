class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> cnt(10);

        while (n > 0) {
            cnt[n%10]++;
            n /= 10;
        }

        for (int i=0; i<=30; i++) {
            int num = 1<<i;
            vector<int> currCnt(10, 0);
            while (num > 0) {
                currCnt[num%10]++;
                num /= 10;
            }
            bool same = true;
            for (int i=0; i<10; i++) {
                if (cnt[i] != currCnt[i]) {
                    same = false;
                    break;
                }
            }
            if (same) {
                return true;
            }
        }

        return false;
    }
};