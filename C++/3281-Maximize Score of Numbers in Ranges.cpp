class Solution {
public:
    int N;
    bool check(int diff, int d, vector<int>& start) {
        int prev = start[0];
        for (int i=1; i<N-1; i++) {
            if (start[i] + d >= prev + diff) {
                prev = max(start[i], prev+diff);
            } else {
                return false;
            }
        }
        if (start.back() + d < prev + diff) return false;
        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        this->N = start.size();
        sort(start.begin(), start.end());
        int left = 0, right = (start.back()+d-start[0])/(N-1);
        
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (check(mid, d, start)) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if (check(right, d, start)) return right;
        return left;
    }
};