from collections import defaultdict
class Solution(object):
    def canCross(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
# Time complexity: O(n^2) (two nested loops)
# Space complexity: O(n^2)

        hmap = defaultdict(set)
        
        for i in range(len(stones)):
            hmap[stones[i]] = set()
            
        hmap[0].add(0)
        
        for i in range(len(stones)):
            for jump in hmap[stones[i]]:
                for diff in (-1,0,1):
                    if jump + diff > 0:
                        hmap[stones[i]+jump+diff].add(jump+diff)
        return hmap[stones[-1]]