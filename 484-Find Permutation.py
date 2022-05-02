class Solution(object):
    def findPermutation(self, s):
        """
        :type s: str
        :rtype: List[int]
        """
# stack
        stack = []
        res = []
        for i in range(1, len(s)+1):
            if s[i-1] == "I":
                stack.append(i)
                while stack:
                    res.append(stack.pop())
            else:
                stack.append(i)
        
        stack.append(len(s)+1)
        while stack:
            res.append(stack.pop())
            
        return res
    
    
# reverse array
        res = [i for i in range(1, len(s)+2)]
        
        def reverse(start, end):
            while start < end:
                res[start], res[end] = res[end], res[start]
                start += 1
                end -= 1
    
        i = 1
        while i < len(res):
            if s[i-1] == "D":
                start = i-1
                while i < len(res) and s[i-1] == "D":
                    i+=1
                reverse(start, i-1)
            else:
                i+=1
        
        return res