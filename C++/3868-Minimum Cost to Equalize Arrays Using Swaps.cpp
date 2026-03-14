class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cnt, cnt1;
        for (int i=0; i<nums1.size(); i++) {
            cnt1[nums1[i]]++;
            cnt[nums1[i]]++;
        }

        for (int i=0; i<nums2.size(); i++) {
            cnt[nums2[i]]++;
        }

        for (auto &[k, v]:cnt) {
            if (v%2) return -1;
        }

        int res = 0;
        for (auto &[k, v]:cnt1) {
            if (v > cnt[k]/2) {
                res += v - cnt[k]/2;
            }
        }

        return res;
    }
};


// Clever solution
class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cnt;

        for (int num:nums1) cnt[num]++;
        for (int num:nums2) cnt[num]--;

        int diff = 0;

        for (auto &[k, v]:cnt) {
            if (v%2) return -1;
            diff += abs(v);
        }

        return diff/4;
    }
};