class Solution {
public:
    bool isOK(vector<int>& bloomDay, int m, int k, int mid) {
        int cnt = 0, curr = 0;
        for (int b:bloomDay) {
            if (b <= mid) {
                curr += 1;
                if (curr == k) {
                    cnt++;
                    curr = 0;
                }
            } else {
                curr = 0;
            }
        }

        return cnt >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int N = bloomDay.size();
        if ((long long)m*k > N) return -1;

        int left = 0, right = *max_element(bloomDay.begin(), bloomDay.end());

        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (isOK(bloomDay, m, k, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (isOK(bloomDay, m, k, left)) {
            return left;
        }
        return right;
    }
};