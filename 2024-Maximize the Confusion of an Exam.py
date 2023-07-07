class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:        
# First try, two sliding windows
        N = len(answerKey)
        res = 0

        left = 0
        fcount = 0
        for i in range(N):
            if answerKey[i] == "F":
                fcount += 1
            if fcount > k:
                if answerKey[left] == "F":
                    fcount -= 1
                left += 1        
            res = max(res, i- left +1)
        
        left = 0
        tcount = 0
        for i in range(N):
            if answerKey[i] == "T":
                tcount += 1
            if tcount > k:
                if answerKey[left] == "T":
                    tcount -= 1
                left += 1
            res = max(res, i- left +1)
        
        return res
    
    
# Fastest sliding window solution
        count = defaultdict(int)
        N = len(answerKey)
        res = 0
        
        for i in range(N):
            count[answerKey[i]] += 1
            
            if min(count['T'], count['F']) <= k:
                res += 1
            else:
                count[answerKey[i-res]] -= 1
        
        return res