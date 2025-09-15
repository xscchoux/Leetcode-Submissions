class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int res = 0, N = arrivals.size();
        unordered_map<int, int> cnt;
        vector<bool> removed(N, false);

        for (int i=0; i<arrivals.size(); i++) {
            cnt[arrivals[i]]++;
            if (cnt[arrivals[i]] > m) {
                cnt[arrivals[i]]--;
                res++;
                removed[i] = true;
            }
            if (i-w+1 >= 0 && !removed[i-w+1]) {
                cnt[arrivals[i-w+1]]--;
            }
        }

        return res;
    }
};