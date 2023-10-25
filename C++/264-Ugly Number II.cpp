class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res = {1};
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i=1; i<n; i++){
            // pick the added ugly numbers that have not multiply by 2 or 3 or 5 yet
            int nxt = min(res[i2]*2, min(res[i3]*3, res[i5]*5));   
            if (nxt == res[i2]*2) i2++;
            if (nxt == res[i3]*3) i3++;
            if (nxt == res[i5]*5) i5++;
            res.push_back(nxt);
        }
        return res[res.size()-1];
    }
};