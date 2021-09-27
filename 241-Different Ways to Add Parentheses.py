class Solution(object):
    def diffWaysToCompute(self, expression):
        """
        :type expression: str
        :rtype: List[int]
        """
        memo = dict()
        
        def cal(start, end):
            if (start, end) in memo:
                return memo[(start, end)]
            if expression[start: end+1].isdigit():
                return [int(expression[start:end+1])]
            res = []
            for i in range(start, end+1):
                if expression[i] in ("+","-","*"):
                    left = cal(start, i-1)
                    right = cal(i+1, end)
                    for l in left:
                        for r in right:
                            if expression[i] == "+":
                                res.append(int(l)+int(r))
                            elif expression[i] == "-":
                                res.append(int(l)-int(r))
                            else:
                                res.append(int(l)*int(r))
            
            memo[(start, end)] = res
            return res
        
        return cal(0, len(expression)-1)