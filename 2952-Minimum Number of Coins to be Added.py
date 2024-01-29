class Solution:
    def minimumAddedCoins(self, coins: List[int], target: int) -> int:
        coins.sort()
        farthest = 0
        res = 0
        
        for coin in coins:
            while farthest + 1 < coin and farthest < target:
                res += 1
                farthest += farthest+1
            
            farthest += coin
            
            if farthest >= target:
                return res
            
        while farthest < target:
            farthest += farthest+1
            res += 1
        
        return res