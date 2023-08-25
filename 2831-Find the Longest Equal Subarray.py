class Solution:
    def longestEqualSubarray(self, nums: List[int], k: int) -> int:
    
    # sliding window + deque
        hmap = defaultdict(deque)
        res = 1
        
        for i in range(len(nums)):
            hmap[nums[i]].append(i)
            if len(hmap[nums[i]]) == 1:
                continue
            while (hmap[nums[i]][-1] - hmap[nums[i]][0] + 1) - len(hmap[nums[i]]) > k:
                hmap[nums[i]].popleft()
            res = max(res, len(hmap[nums[i]]))
        
        return res
    
    
    # https://leetcode.com/problems/find-the-longest-equal-subarray/discuss/3934172/JavaC%2B%2BPython-One-Pass-Sliding-Window-O(n)
    # Ingenious solution. Note that this is because hmap[nums[i]] only increase by 1 for each operation in the for loop
    
        hmap = defaultdict(int)
        maxfreq = 0
        left = 0
        
        for i in range(len(nums)):
            hmap[nums[i]] += 1
            if maxfreq < hmap[nums[i]]:
                maxfreq = hmap[nums[i]]
            
            if i - left + 1 - maxfreq > k:
                hmap[nums[left]] -= 1
                left += 1
        
        return maxfreq