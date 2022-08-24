class Solution(object):
    def shiftingLetters(self, s, shifts):
        """
        :type s: str
        :type shifts: List[List[int]]
        :rtype: str
        """
        dp = [0]*len(s)
        
        for start, end, direction in shifts:
            if direction == 0:
                dp[start] -= 1
                if end + 1 <= len(s)-1:
                    dp[end+1] += 1
            else:
                dp[start] += 1
                if end+1 <= len(s)-1:
                    dp[end+1] -= 1
        
        runningVal = 0
        
        res = []
        for i in range(len(dp)):
            runningVal += dp[i]
            curr = ord(s[i]) - ord('a')
            diff = (runningVal%26 + 26 + curr)%26
            res.append(chr(diff+ord('a')))
        
        return "".join(res)