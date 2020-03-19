class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits:
            return []
        
        hmap = {'2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz'}
        n = len(digits)
        res = []
        
        def dfs(start, val):
            if start == n:
                res.append(val)
                return
            for char in hmap[digits[start]]:
                dfs(start+1, val+char)
        dfs(0, "")       
        return res