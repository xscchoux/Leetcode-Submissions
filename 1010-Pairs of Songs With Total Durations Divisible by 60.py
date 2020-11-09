from collections import defaultdict
class Solution(object):
    def numPairsDivisibleBy60(self, time):
        """
        :type time: List[int]
        :rtype: int
        """
        hmap = defaultdict(int)
        count = 0
        
        for t in time:
            pair = 60 - t%60
            if pair == 60:
                pair = 0
            count += hmap[pair]
            hmap[t%60] += 1
        
        return count