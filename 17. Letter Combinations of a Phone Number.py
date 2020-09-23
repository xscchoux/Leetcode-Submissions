class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits:
            return []
            
        hmap = {"2":"abc", "3":"def", "4":"ghi", "5":"jkl", "6":"mno", "7":"pqrs", "8":"tuv", "9":"wxyz"}
        
        res = []
        def dfs(i, val):
            if i == len(digits):
                res.append(val)
                return
            for char in hmap[digits[i]]:
                dfs(i+1, val+char)
        
        dfs(0, "")
        
        return res