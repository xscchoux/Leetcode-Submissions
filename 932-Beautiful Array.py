class Solution(object):
    def beautifulArray(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        res = [1]
        while len(res) < n:
            tmp = []
            
            # add odd numbers
            for i in res:
                if i*2-1 <= n:
                    tmp.append(i*2-1) 
            
            # add even numbers
            for i in res:
                if i*2 <= n:
                    tmp.append(i*2)        
            res = tmp
        
        return res