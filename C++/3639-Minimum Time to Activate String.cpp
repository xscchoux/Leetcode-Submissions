class Solution {
public:
    int N, k;
    bool count(int endTime, vector<int>& order) {
        vector<bool> sArr(N, false);

        for (int t=0; t<=endTime; t++) {
            sArr[order[t]] = true;
        }

        long long cnt = 0;
        int lastStar = -1;
        for (int i=0; i<N; i++) {
            if (!sArr[i]) {
                cnt += lastStar+1;
            } else {
                cnt += i+1;
                lastStar = i;
            }
            if (cnt >= k) return true;
        }

        return false;
    }
    int minTime(string s, vector<int>& order, int k) {
        this->N = s.size();
        this->k = k;
        int left = 0, right = order.size()-1;

        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (count(mid, order)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (count(left, order)) {
            return left;
        } else if (count(right, order)) {
            return right;
        } else {
            return -1;
        }
    }
};