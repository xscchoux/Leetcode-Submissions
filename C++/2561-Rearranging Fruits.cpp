// First AC
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> cnt;
        unordered_map<int, int> cnt1;

        for (int num1:basket1) cnt[num1]++;
        for (int num2:basket2) cnt[num2]++;

        for (auto &[k, v]:cnt) {
            if (v%2 == 1) return -1;
        }

        for (int num1:basket1) cnt1[num1]++;
        
        long long toSwitch = 0;
        for (auto &[k, v]:cnt) {
            if (cnt[k]/2 != cnt1[k]) {
                toSwitch += abs(cnt[k]/2 - cnt1[k]);
            }
        }
        toSwitch /= 2;

        int minVal = begin(cnt)->first;
        long long res = 0;
        for (auto &[k, v]:cnt) {
            if (cnt[k]/2 != cnt1[k]) {
                long long currCnt = min(toSwitch, (long long)abs(cnt1[k]-cnt[k]/2));
                res += min(currCnt*k, 2*currCnt*minVal);
                toSwitch -= currCnt;
                if (toSwitch <= 0) {
                    return res;
                }
            }
        }

        return res;
    }
};


class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> cnt;
        int minVal = INT_MAX;
        for (int num1:basket1) {
            cnt[num1]++;
            minVal = min(minVal, num1);
        }
        for (int num2:basket2) {
            cnt[num2]--;
            minVal = min(minVal, num2);
        }

        vector<int> toSwap;  // There will be even number of elements in toSwap
        for (auto &[k, v]:cnt) {
            if (v%2 != 0) return -1;

            for (int i=0; i<abs(v)/2; i++) {
                toSwap.push_back(k);
            }
        }

        nth_element(begin(toSwap), begin(toSwap) + toSwap.size()/2, end(toSwap));  // use nth_element, no need to sort
        
        long long res = 0;
        for (int i=0; i<toSwap.size()/2; i++) {
            res += min(2*minVal, toSwap[i]);
        }

        return res;
    }
};