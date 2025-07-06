class FindSumPairs {
public:
    vector<int> arr1, arr2;
    unordered_map<int, int> cnt2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;
        for (int num:nums2) {
            cnt2[num]++;
        }
    }
    
    void add(int index, int val) {
        cnt2[arr2[index]]--;
        if (cnt2[arr2[index]] == 0) {
            cnt2.erase(arr2[index]);
        }
        arr2[index] += val;
        cnt2[arr2[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        for (int num:arr1) {
            if (cnt2.contains(tot-num)) {
                res += cnt2[tot-num];
            }
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */