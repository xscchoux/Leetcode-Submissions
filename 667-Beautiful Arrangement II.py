class Solution(object):
    def constructArray(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        left, right = 1, n
        res = []
        
        isOdd = True
        tmp = k
        
        while tmp > 0:
            if isOdd:
                res.append(left)
                left+=1
            else:
                res.append(right)
                right-=1
            tmp -= 1
            isOdd = not isOdd
        
        if k%2:
            res += list(range(left, right+1))
        else:
            res += list(range(right, left-1, -1))
                
        return res