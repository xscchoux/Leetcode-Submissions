class Solution:
    def minimumString(self, a: str, b: str, c: str) -> str:
        length = len(a) + len(b) + len(c)
        string = a+b+c
        
        @cache
        def connect(s1, s2):
            # if 
            if s2 in s1:
                return s1
            
            res = 0
            for i in range(1, min(len(s1), len(s2)) + 1):
                if s1[-i:] == s2[:i]:
                    res = i
                    
            return s1 + s2[res:]
        
        for u, v, w in ((a, b, c), (a, c, b), (b, a, c), (b, c, a), (c, a, b), (c, b, a)):
            curr = connect(connect(u, v), w)
            if len(curr) < length:
                string = curr
                length = len(string)
            elif len(curr) == length:
                string = min(string, curr)
            
        return string
