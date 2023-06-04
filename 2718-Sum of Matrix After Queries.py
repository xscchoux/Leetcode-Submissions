class Solution:
    def matrixSumQueries(self, n: int, queries: List[List[int]]) -> int:
        tot = 0
        usedR, usedC = set(), set()
        
        for t, idx, val in queries[::-1]:
            if t == 0:
                if idx not in usedR:
                    tot += val*(n - len(usedC))
                    usedR.add(idx)
            else:
                if idx not in usedC:
                    tot += val*(n - len(usedR))
                    usedC.add(idx)
        
        return tot