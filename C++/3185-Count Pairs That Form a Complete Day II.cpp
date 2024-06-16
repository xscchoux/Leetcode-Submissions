class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int N = hours.size();
        for (int i=0; i<N; i++) hours[i] = hours[i]%24;

        unordered_map<int, int> cnt;
        long long res = 0;
        for (int h:hours) {
            if (cnt.contains((24-h)%24)) {
                res += cnt[(24-h)%24];
            }
            cnt[h]++;
        }

        return res;
    }
};