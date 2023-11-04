class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        # https://www.cnblogs.com/grandyang/p/6031787.html
        # consider the prefix with start = 1 and end = 2 first
        # count += (2-1) + (20-10) + ... + min(n+1, 2*10^x) - 10^x
        # if k - count >= 1, move start to 2 and end to 3. k -= count
        # else k -= 1 ( remove the case when we the number "equals to start (start == 1 here)"). And then consider start = 10, end = 20
        

#         res = 1
        
#         while k > 1:  # Stop when k == 1
#             start, end = res, res+1
#             count = 0
#             while start <= n:
#                 count += min(end, n+1) - start
#                 start *= 10
#                 end *= 10
            
#             if k - count >= 1:
#                 k -= count
#                 res += 1
#             else:
#                 k -= 1
#                 res *= 10
        
#         return res
    
    
# It might be a bit simpler if we subtract 1 from k first 
        res = 1
        k -= 1
        
        while k > 0:  # Stop when k == 0
            start, end = res, res+1
            count = 0
            while start <= n:
                count += min(end, n+1) - start
                start *= 10
                end *= 10
            
            if k >= count:
                k -= count
                res += 1
            else:
                k -= 1
                res *= 10
        
        return res