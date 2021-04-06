from collections import Counter
class Solution(object):
    def isPossible(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
# greedy
# consider 3 cases:
# 1. add current number to previous consecutive subseqence if exists
# 2. check if current number + 1 & current number + 2 exists, if yes, create a new consecutive subsequence
# 3. return false

        freq = Counter(nums)
        last = defaultdict(int)
        
        for num in nums:
            if freq[num]:
                if last[num-1]:
                    last[num-1]-=1
                    last[num]+=1
                elif freq[num+1] and freq[num+2]:
                    freq[num+1]-=1
                    freq[num+2]-=1
                    last[num+2]+=1
                else:
                    return False
                freq[num]-=1
        
        return True