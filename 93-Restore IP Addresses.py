class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        self.res = []
        
        def dfs(remain, space, address):
            if space == 0:
                if not remain:
                    self.res.append(".".join(address))
                return
            else:
                if not remain:
                    return
                
            remainLen = len(remain)
            
            if remain[0] == "0" and 0<=remainLen-1 <= 3*(space-1):
                dfs(remain[1:], space-1, address + ["0"])            
            for i in range(1, 4):
                if remain[0] != "0" and 0<=remainLen-i <= 3*(space-1) and 1 <= int(remain[:i]) <= 255 :
                    dfs(remain[i:], space-1, address + [remain[:i]])

        N = len(s) 
        
        dfs(s, 4, [])
        
        return self.res