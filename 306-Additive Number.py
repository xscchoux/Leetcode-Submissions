class Solution(object):
    def isAdditiveNumber(self, num):
        """
        :type num: str
        :rtype: bool
        """
# O(2^n)        

# first try, it passed! unbelievable!        
        arr = []
        self.boolean = False
        N = len(num)
        def dfs(start):
            for i in range(start+1, len(num)+1):
                if self.boolean:
                    return
                if num[start] == '0' and i-start != 1:
                    break
                    
                elif len(arr) < 2:
                    arr.append( int(num[start:i]) )
                    dfs(i)
                    arr.pop()
                else:
                    if int(arr[-1]) + int(arr[-2]) < int(num[start:i]):
                        break
                    if int(arr[-1]) + int(arr[-2]) == int(num[start:i]):
                        arr.append( int(num[start:i]) )
                        if i == N:
                            self.boolean = True
                        dfs(i)
                        arr.pop()
        dfs(0)
        return self.boolean

# simplify
        arr = []
        N = len(num)
        if N <3:
            return False
        
        def dfs(start):
            if start == N and len(arr) >=3:
                return True
            for i in range(start+1, len(num)+1):
                if num[start] == '0' and i-start != 1:
                    return False
                elif len(arr) < 2:
                    arr.append( int(num[start:i]) )
                    if dfs(i):
                        return True
                    arr.pop()
                else:
                    if int(arr[-1]) + int(arr[-2]) < int(num[start:i]):
                        return False
                    if int(arr[-1]) + int(arr[-2]) == int(num[start:i]):
                        arr.append( int(num[start:i]) )
                        if dfs(i):
                            return True
                        arr.pop()
        res = dfs(0)
        return res