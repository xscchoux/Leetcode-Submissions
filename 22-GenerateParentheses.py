class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        def dfs(left, right, val):
            if left == n and right == n:
                res.append(val)
            if left < n:
                dfs(left+1, right, val+"(")
            if left>right:
                dfs(left, right+1, val+")")        
        dfs(0,0,"")
        return res