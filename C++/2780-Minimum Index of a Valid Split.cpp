// two map pairs
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int N = nums.size();
        map<int, set<int>, greater<>> cnt1, cnt2; // count to number
        unordered_map<int, int> mLeft, mRight;  // number:count

        for (int i=0; i<N; i++) {
            mRight[nums[i]]++;
        }

        for (auto &[k, v]:mRight) {
            cnt2[v].insert(k);
        }

        for (int i=0; i<N-1; i++) {
            int currRightCnt = mRight[nums[i]];
            cnt2[currRightCnt].erase(nums[i]);
            if (cnt2[currRightCnt].empty()) {
                cnt2.erase(currRightCnt);
            }
            cnt2[currRightCnt-1].insert(nums[i]);

            int currLeftCnt = mLeft[nums[i]];
            if (currLeftCnt > 0) cnt1[currLeftCnt].erase(nums[i]);
            if (cnt1[currLeftCnt].empty()) {
                cnt1.erase(currLeftCnt);
            }
            cnt1[currLeftCnt+1].insert(nums[i]);

            mLeft[nums[i]]++;
            mRight[nums[i]]--;
            int leftFirst = *(begin(cnt1)->second.begin());
            int rightFirst = *(begin(cnt2)->second.begin());
            if (leftFirst == rightFirst && mLeft[leftFirst] > (i+1)/2 && mRight[rightFirst] > (N-i-1)/2) {
                return i;
            }
        }

        return -1;

    }
};


// Just find the dominant element in nums
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int maxFreq = -1, dominantNum = -1, N = nums.size();

        for (int num:nums) {
            cnt[num]++;
            if (cnt[num] > maxFreq) {
                maxFreq = cnt[num];
                dominantNum = num;
            }
        }

        int prefix = 0, suffix = maxFreq;

        for (int i=0; i<N-1; i++) {
            if (nums[i] == dominantNum) {
                prefix++;
                suffix--;

                if (prefix > (i+1)/2 && suffix > (N-i-1)/2) {
                    return i;
                }
            }
        }

        return -1;
    }
};