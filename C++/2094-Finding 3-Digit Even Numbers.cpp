class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> cnt(10), res;
        for (int d:digits) cnt[d]++;

        for (int num = 100; num<1000; num+=2) {
            int tmp = num, c = tmp%10;
            tmp /= 10;
            int b = tmp%10, a = tmp/10;
            cnt[a]--; cnt[b]--; cnt[c]--;
            if (cnt[a]>=0 && cnt[b]>=0 && cnt[c]>=0) {
                res.push_back(a*100+b*10+c);
            }
            cnt[a]++; cnt[b]++; cnt[c]++;            
        }

        return res;
    }
};