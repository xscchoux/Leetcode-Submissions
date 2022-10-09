class Solution(object):
   def robotWithString(self, s):
       """
       :type s: str
       :rtype: str
       """
       smallest = [i for i in range(len(s))]
       small = float('inf')
       smallIdx = len(s) - 1
       
       for i in range(len(s)-1, -1, -1):
           if ord(s[i]) - ord('a') <= small:
               small = ord(s[i]) - ord('a')
               smallIdx = i
           smallest[i] = smallIdx

       res = []
       t = []
       
       while i < len(s):
           while t and s[smallest[i]] >= robot[-1]:
               res.append(t.pop())
           for j in range(i, smallest[i] + 1):
               t.append(s[j])
           i = smallest[i] + 1
       
       while t:
           res.append(t.pop())
           
       return "".join(res)