class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        hmap = defaultdict(int) # number:count
        res = 1
        for i in range(len(arr)):
            hmap[arr[i]] = hmap[arr[i]-difference] + 1
            res = max(res, hmap[arr[i]])
            
        return res