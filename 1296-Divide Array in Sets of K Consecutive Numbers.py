from collections import Counter
class Solution(object):
    def isPossibleDivide(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        freq = Counter(nums)
        
        for key in sorted(freq):
            if freq[key]:
                for m in range(key+k-1, key, -1):
                    if freq[m] < freq[key]:
                        return False
                    freq[m] -= freq[key]
                freq[key] = 0
            
        return True