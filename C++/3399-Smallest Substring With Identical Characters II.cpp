class Solution {
public:
    int N;
    bool isOK(string& s, int mid, int numOps) {
        if (mid == 1) {
            // start with '0'
            char curr = '0';
            int cnt1 = 0;
            for (int i=0; i<N; i++) {
                if (s[i] != curr) cnt1++;
                curr = (curr=='0')?'1':'0';
            }
            // start with '1'
            curr = '1';
            int cnt2 = 0;
            for (int i=0; i<N; i++) {
                if (s[i] != curr) cnt2++;
                curr = (curr=='0')?'1':'0';
            }
            return min(cnt1, cnt2) <= numOps;
        } else {
            int count = 0;
            char last = 'n';
            for (int i=0; i<N; i++) {
                if (s[i] == last) {
                    count++;
                } else {
                    numOps -= count/(mid+1);
                    last = s[i];
                    count = 1;
                }
            }
            numOps -= count/(mid+1);
            return numOps>=0;
        }
    }
    int minLength(string s, int numOps) {
        N = s.size();
        int left = 1, right = N;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (isOK(s, mid, numOps)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (isOK(s, left, numOps)) return left;
        return right;
    }
};