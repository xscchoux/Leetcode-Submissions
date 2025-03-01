class Solution {
public:
    int minSwaps(vector<int>& data) {
        int one = accumulate(begin(data), end(data), 0);

        int curr = 0;
        for (int i=0; i<one; i++) {
            if (data[i] == 1) curr++;
        }
        int res = one-curr;

        for (int i=one; i<data.size(); i++) {
            if (data[i] == 1) curr++;
            if (data[i-one] == 1) curr--;
            res = min(res, one-curr);
        }

        return res;
    }
};