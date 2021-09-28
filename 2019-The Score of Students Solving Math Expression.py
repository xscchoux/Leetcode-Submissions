class Solution(object):
    def scoreOfStudents(self, s, answers):
        """
        :type s: str
        :type answers: List[int]
        :rtype: int
        """
        correct = eval(s)
        
        candidate = set()
        memo = dict()
        
        def cal(start, end):
            if (start, end) in memo:
                return memo[(start, end)]
            if start == end:
                return [int(s[start])]
            
            res = set()
            
            for i in range(start, end+1):
                if s[i] in ("+", "-", "*"):
                    left = cal(start, i-1)
                    right = cal(i+1, end)
                    for l in left:
                        for r in right:
                            if s[i] == "+" and l + r <= 1000:
                                res.add(l+r)
                            elif s[i] == "*" and l*r <= 1000:
                                res.add(l*r)
            memo[(start, end)] = res
            return res
        
        candidates = cal(0, len(s)-1)

        ans = 0
        for answer in answers:
            if answer == correct:
                ans+=5
            elif answer in candidates:
                ans+=2
                
        return ans