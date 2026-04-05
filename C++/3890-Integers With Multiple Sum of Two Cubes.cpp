bool computed = false;
vector<int> resNum;
void cal() {
    map<int, int> cnt;
    for (int i=1; i<=1000; i++) {
        for (int j=i; j<=1000; j++) {
            cnt[i*i*i + j*j*j]++;
        }
    }
    for (auto &[k, v]:cnt) {
        if (v >= 2) {
            resNum.push_back(k);
        }
    }
    computed  = true;

}

class Solution {
public:
    Solution() {
        if (!computed) {
            cal();
        }
    }
    vector<int> findGoodIntegers(int n) {
        vector<int> res;
        for (int num:resNum) {
            if (num > n) break;
            res.push_back(num);
        }

        return res;
    }
};