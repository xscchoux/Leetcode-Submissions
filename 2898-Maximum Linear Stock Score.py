class Solution:
    def maxScore(self, prices: List[int]) -> int:
        hmap = defaultdict(int)
        for ind, val in enumerate(prices, 1):
            hmap[val-ind] += val
        
        return max(hmap.values())