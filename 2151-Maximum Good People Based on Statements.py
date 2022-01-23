class Solution(object):
    def maximumGood(self, statements):
        """
        :type statements: List[List[int]]
        :rtype: int
        """
        N = len(statements[0])
        sayGood = [[] for _ in range(N)]
        sayBad = [[] for _ in range(N)]

        for r in range(N):
            for c in range(N):
                if statements[r][c] == 1:
                    sayGood[c].append(r)
                elif statements[r][c] == 0:
                    sayBad[c].append(r)

        mask = (1<<N) - 1
        res = 0
        
        while mask > 0:
            check = True
            for i in range(N):    
                if (mask>>i)&1: # if good person
                    for j in range(len(sayBad[i])):
                        if (mask>>sayBad[i][j]) & 1:
                            check = False
                            break
            
                if (mask>>i)&1 == 0:
                    for k in range(len(sayGood[i])):
                        if (mask>>sayGood[i][k]) & 1:
                            check = False
                            break
            if check:
                res = max(res, sum([(mask>>i)&1 for i in range(N)]))
            mask -= 1
            
        return res