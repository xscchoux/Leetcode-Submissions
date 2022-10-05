class Solution:
    def maxEqualFreq(self, nums: List[int]) -> int:
        
# https://leetcode.com/problems/maximum-equal-frequency/discuss/403628/Easy-Python-Solution-Concise-10-lines-Explained-O(N)
        maxF = 0
        count = collections.defaultdict(int)
        freqCount = collections.defaultdict(int)
        res = 0
        
        for i in range(len(nums)):
            freqCount[count[nums[i]]] -= 1
            freqCount[count[nums[i]] + 1] += 1
            count[nums[i]] += 1
            
            maxF = max(maxF, count[nums[i]])
            
            if maxF == 1 or (maxF-1)*(freqCount[maxF-1] + 1) == i or maxF*freqCount[maxF] == i:
                res = i + 1

        return res