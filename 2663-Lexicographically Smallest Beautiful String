class Solution:
    def smallestBeautifulString(self, s: str, k: int) -> str:
        res = []
        for c in s:
            res.append(ord(c)-ord('a'))
        
        def isOK(idx):
            if idx > 0 and res[idx] == res[idx-1]:
                return False
            if idx > 1 and res[idx] == res[idx-2]:
                return False
            return True
        
        for i in range(len(s)-1, -1, -1):
            if res[i] + 1 == k:
                continue
            while res[i] + 1 < k:
                res[i] += 1
                flag = False
                if isOK(i):
                    flag = True
                    for j in range(i+1, len(s)):
                        for ch in range(k):
                            res[j] = ch
                            if isOK(j):
                                break
                if flag:
                    return "".join(map(lambda x:chr(x+97) ,res))
        return ""
    
# while loop solution, more concise
        res = []
        for c in s:
            res.append(ord(c)-ord('a'))
        
        res[len(s)-1] += 1
        idx = len(s) - 1
        
        while idx < len(s):
            if res[idx] == k:
                res[idx] = 0
                idx -= 1
                if idx < 0:
                    return ""
                res[idx] += 1
            elif (idx > 0 and res[idx-1] == res[idx]) or (idx > 1 and res[idx-2] == res[idx]):
                res[idx] += 1
            else:
                idx += 1
        
        return "".join(map(lambda x:chr(x+97) ,res))