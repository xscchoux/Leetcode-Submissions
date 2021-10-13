class Solution(object):
    def totalFruit(self, fruits):
        """
        :type fruits: List[int]
        :rtype: int
        """
        hmap = collections.defaultdict(int)
        N = len(fruits)
        left = 0
        res = 0
        
        for i in range(N):
            hmap[fruits[i]] += 1
            while len(hmap) > 2:
                hmap[fruits[left]] -= 1
                if hmap[fruits[left]] == 0:
                    del hmap[fruits[left]]
                left += 1
            res = max(i-left+1, res)
            
        return res