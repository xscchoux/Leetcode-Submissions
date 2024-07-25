// The length of the longest non-increasing subsequence corresponds to the number of strictly increasing subsequence
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int N = nums.size();
        vector<int> nonDec;  // obtain the length of the longest non-decreasing subsequence
        reverse(nums.begin(), nums.end());

        for (int i=0; i<N; i++) {
            auto it = upper_bound(nonDec.begin(), nonDec.end(), nums[i]);
            if (it == nonDec.end()) {
                nonDec.push_back(nums[i]);
            } else {
                int idx = it - nonDec.begin();
                nonDec[idx] = nums[i];
            }
        }

        return nonDec.size();
    }
};

// Use multiset. Slower but very concise
class Solution {
public:
    int minOperations(vector<int>& nums) {
        multiset<int, greater<>> s;  // keep a non-increasing subsequence
        for (int num:nums) {
            auto it = s.upper_bound(num);  // s.upper_bound(x) returns an iterator to the first element in the multiset that is strictly less than x
            if (it != s.end()) {
                s.erase(it);
            }
            s.insert(num);
        }
        return s.size();
    }
};