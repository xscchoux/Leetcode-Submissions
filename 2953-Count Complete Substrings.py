class Solution:
    def countCompleteSubstrings(self, word: str, k: int) -> int:
        N = len(word)
        
        # window length:k, 2*k, 3*k, ..., 26*k
        res = 0
        
        def cal(left, right):
            length = right-left+1
            res = 0
            for l in range(1, 27):
                if l*k > length:
                    break

                tmp = [0]*26
                currLen = l*k
                leftBound = left
                
                for i in range(left, right+1):
                    tmp[ord(word[i])-ord('a')] += 1
                    
                    if i-leftBound >= currLen:
                        tmp[ord(word[i-currLen])-ord('a')] -= 1
                        leftBound+=1
                    
                    if i-leftBound >= currLen-1:
                        if all(v == k or v == 0 for v in tmp):
                            res += 1
                    
            return res
        
        start = 0
        
        for i in range(N-1):
            if abs(ord(word[i])-ord(word[i+1])) > 2:
                res += cal(start, i)
                start = i+1

        res += cal(start, N-1)
        
        return res