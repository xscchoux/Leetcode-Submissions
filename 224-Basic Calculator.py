class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        def dfs(ind):
            tot = 0
            sign = 1
            while ind < len(s):
                if s[ind].isdigit():
                    num = 0
                    while ind < len(s) and s[ind].isdigit():
                        num = num*10 + int(s[ind])
                        ind += 1
                    tot += sign*num
                elif s[ind] == " ":
                    ind += 1
                elif s[ind] == "+":
                    sign = 1
                    ind += 1
                elif s[ind] == "-":
                    sign = -1
                    ind += 1
                elif s[ind] == "(":
                    res, ind = dfs(ind+1)
                    tot += sign*res
                elif s[ind] == ")":
                    return tot, ind+1
            return tot, ind
        
        return dfs(0)[0]