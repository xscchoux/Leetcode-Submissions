class Solution:
    def kthLuckyNumber(self, k: int) -> str:
        
        def S(n):
            return 2*(pow(2, n) - 1)
            
        left, right = 0, 30
        while left + 1 < right:
            mid = left + (right-left)//2
            if S(mid) > k:
                right = mid
            else:
                left = mid
                
        largest = left
        remain = k - S(largest)

        if remain == 0:
            return "7"*largest
        else:
            return bin(remain-1)[2:].zfill(largest+1).replace('0', '4').replace('1', '7')