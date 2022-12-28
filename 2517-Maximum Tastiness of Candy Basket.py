class Solution:
    def maximumTastiness(self, price: List[int], k: int) -> int:
        
        price.sort()
        
        low, high = 0, price[-1]-price[0]
        
        def count(num):
            cnt = 1
            nxt = price[0] + num
            for i in range(len(price)):
                if price[i] >= nxt:
                    cnt += 1
                    nxt = price[i] + num
            return cnt
        
        while low + 1 < high:
            mid = low + (high-low)//2
            if count(mid) >= k:
                low = mid
            else:
                high = mid
        
        if count(high) >= k:
            return high
        else:
            return low