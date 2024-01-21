class Solution {
public:
    int getBits(int num) {
        int res = 0;
        while (num) {
            res++;
            num = num&(num-1);
        }
        return res;
    }
    
    bool canSortArray(vector<int>& nums) {
        int N = nums.size();
        unordered_map<int, int> bitMap;
        for (int i=0; i<N; i++) {
            if (bitMap.find(nums[i]) == bitMap.end()) {
                bitMap[nums[i]] = getBits(nums[i]);
            }
        }

        for (int i=0; i<N; i++) {
            for (int j=0; j<N-1-i; j++) {
                if (nums[j] > nums[j+1]) {
                    if (bitMap[nums[j]] != bitMap[nums[j+1]]) {
                        return false;
                    }
                    swap(nums[j], nums[j+1]);
                }
            }
        }
        return true;
    }
};