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


// O(nlogn) solution by myself
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int groupNum = 0;
        unordered_map<int, int> mapping; // index: groupNumber
        int preBitCount = 0;

        for (int i=0; i<nums.size(); i++) {
            int currBitCount = __builtin_popcount(nums[i]);
            if (currBitCount == preBitCount) {
                mapping[i] = groupNum;
            } else {
                mapping[i] = ++groupNum;
                preBitCount = currBitCount;
            }   
        }

        vector<pair<int, int>> sortedNum;
        for (int i=0; i<nums.size(); i++) {
            sortedNum.push_back({nums[i], i});
        }

        sort(sortedNum.begin(), sortedNum.end());

        for (int i=0; i<nums.size(); i++) {
            if (mapping[i] != mapping[sortedNum[i].second]) {
                return false;
            }
        }

        return true;
    }
};