class Solution(object):
    def maxProduct(self, s):
        """
        :type s: str
        :rtype: int
        """
        # dp[i][j]: maximum length of palindrome in string[i:j+1]
        def cal(state):
            string = ""
            state = bin(state)[2:]
            
            Nstate = len(state)
            for i in range(Nstate-1, -1, -1):
                if state[i] == "1":
                    string = s[N-1-(Nstate-1-i)] + string
            
            Nstring = len(string)
            dp = [ [0]*Nstring for _ in range(Nstring) ]
            for i in range(Nstring):
                dp[i][i] = 1
            
            for length in range(2, Nstring+1):
                for start in range(Nstring-length+1):
                    end = start+length-1
                    if string[start] == string[end]:
                        dp[start][end] = dp[start+1][end-1] + 2
                    else:
                        dp[start][end] = max(dp[start+1][end], dp[start][end-1])
            return dp[0][Nstring-1]
            
        N = len(s)
        res = 0
        for state in range(1, (1<<N)-1 ):
            res = max(res, cal(state)*cal((1<<N)-1-state) )
        return res