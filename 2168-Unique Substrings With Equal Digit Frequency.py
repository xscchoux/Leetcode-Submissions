class Solution(object):
    def equalDigitFrequency(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        kMod = 1000000007
        res = set()
        
        for i in range(n):
            currHash = 0
            count = [0]*10
            for j in range(i, n):
                currHash = (currHash*11 + int(s[j]) + 1)%kMod
                count[int(s[j])] += 1
                freq = -1
                canPut = True
                for k in range(10):
                    if count[k] == 0:
                        continue
                    if freq == -1:
                        freq = count[k]
                    else:
                        if count[k] != freq:
                            canPut = False
                            break
                if canPut:
                    res.add(currHash)
        return len(res)