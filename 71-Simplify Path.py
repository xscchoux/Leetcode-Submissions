class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        stack = path.split("/")
        res = []
        for i in range(len(stack)):
            if stack[i] == "..":
                if res:
                    res.pop()
        
            elif stack[i] and stack[i] != ".":
                res.append(stack[i])
        
        return "/" + "/".join(res)