class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        res = [0]*(num+1)
        
        for i in range(1,num+1):
            if i%2 == 0:
                res[i] = res[i//2]
            else:
                res[i] = res[i-1] + 1
                
        return res


# DP + Least Significant Bit
        res = [0]*(n+1)
        for num in range(1, n+1):
            res[num] = res[num//2] + (num&1)
        
        return res
    
# DP + Last Set Bit
        res = [0]*(n+1)
        for num in range(1, n+1):
            res[num] = res[num&(num-1)] + 1
        
        return res