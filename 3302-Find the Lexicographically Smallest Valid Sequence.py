class Solution:
    def validSequence(self, word1: str, word2: str) -> List[int]:
        N1, N2 = len(word1), len(word2)
        last = [-1]*N2

        idx2 = N2-1
        for i in range(N1-1, -1, -1):
            if word1[i] == word2[idx2]:
                last[idx2] = i
                idx2 -= 1
            if idx2 < 0:
                break
        
        wild = 1
        idx2 = 0
        res = []
        for i in range(N1):
            if idx2 == N2:
                break
            if word1[i] == word2[idx2]:
                res.append(i)
                idx2 += 1
            elif wild == 1 and (idx2 == N2-1 or i+1 <= last[idx2+1]):
                wild -= 1
                res.append(i)
                idx2 += 1
        
        return res if len(res) == N2 else []