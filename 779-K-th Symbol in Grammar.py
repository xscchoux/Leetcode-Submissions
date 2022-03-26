class Solution(object):
    def kthGrammar(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        def dfs(n, k):
            if n == 1:
                return 0
            if dfs(n-1, (k+1)//2) == 0:
                if k%2 == 0:
                    return 1
                else:
                    return 0
            else:
                if k%2 == 0:
                    return 0
                else:
                    return 1
        
        return dfs(n, k)