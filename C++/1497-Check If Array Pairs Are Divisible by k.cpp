class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> cnt;
        for (int num:arr) {
            int pairVal = (k-num%k)%k;
            if (!cnt.empty() && cnt.contains(pairVal)) {
                cnt[pairVal]--;
                if (cnt[pairVal] == 0) cnt.erase(pairVal);
            } else {
                cnt[(k+num%k)%k]++;
            }
        }

        return cnt.empty();
    }
};