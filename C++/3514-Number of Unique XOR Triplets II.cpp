class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        sort(begin(nums), end(nums));
        unordered_set<int> res;
        vector<int> arr;
        for (int i=0; i<nums.size(); i++) {
            if (i==0||nums[i] != nums[i-1]) {
                arr.push_back(nums[i]);
            }
            res.insert(nums[i]);
        }

        int N = arr.size();
        unordered_set<int> preXOR;
        for (int i=0; i<N; i++) {
            if (i >= 2) {
                for (auto &p:preXOR) {
                    res.insert(arr[i]^p);
                }
            }

            for (int j=0; j<i; j++) {
                preXOR.insert(arr[i]^arr[j]);
            }
        }

        return res.size();
    }
};