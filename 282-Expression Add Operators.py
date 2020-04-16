class Solution(object):
    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        
        res = []
        def dfs(start, expression, curVal, prev):
            if start >= len(num):
                if curVal == target:
                    res.append(expression)
                return
            for i in range(start+1, len(num)+1):
                if num[start] == '0' and i-start > 1:
                    break
                number = int(num[start:i])
                if start == 0:
                    dfs(i, num[start:i], number, number)
                else:
                    dfs(i, expression + "+" + num[start:i], curVal+number, number)
                    dfs(i, expression + "-" + num[start:i], curVal-number, -number)
                    dfs(i, expression + "*" + num[start:i], curVal-prev+prev*number, prev*number) 
        dfs(0, "", 0, 0)
        
        return res