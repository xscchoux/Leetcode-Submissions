class Solution:
    def countPalindromes(self, s: str) -> int:
        
# slower
        kMod = 1000000007
        res = 0
        
        for x in range(10):
            for y in range(10):
                pattern = f"{x}{y}|{y}{x}"
                dp = [0]*6
                dp[0] = 1
                for i in range(len(s)):
                    for j in range(4, -1, -1):
                        if s[i] == pattern[j] or j == 2:
                            dp[j+1] = (dp`[j+1] + dp[j])%kMod
                res = (res + dp[-1])%kMod
        return res
    
# calculate left and then right, very brilliant solution

        kMod = 1000000007
        res = 0
        
        left_1, left_2 = [0]*10, [0]*100
        right_1, right_2 = [0]*10, [0]*100
        
        for i in range(len(s)):
            curr = int(s[i])
            for k in range(10):
                left_2[k*10 + curr] += left_1[k]
            left_1[curr] += 1
            
        for i in range(len(s)-1, -1, -1):
            curr = int(s[i])
            left_1[curr] -= 1
            for k in range(10):
                left_2[k*10+curr] -= left_1[k]
                
            for j in range(100):
                res = (res + left_2[j]*right_2[j])%kMod
                
            for k in range(10):
                right_2[k*10+curr] += right_1[k]
            right_1[curr] += 1
            
        
        return res