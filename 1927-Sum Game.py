class Solution(object):
    def sumGame(self, num):
        """
        :type num: str
        :rtype: bool
        """
# https://leetcode.com/problems/sum-game/discuss/1328966/JavaC%2B%2BPython-Math-Problem-with-Explanation
        N = len(num)
        diff = cnt = 0
        
        for ind, val in enumerate(num):
            if ind < N//2:
                if val == "?":
                    cnt += 1
                else:
                    diff += int(val)
            else:
                if val == "?":
                    cnt -= 1
                else:
                    diff -= int(val)
                    
        if cnt%2:
            return True
        
        if (diff>0 and cnt >=0) or (diff<0 and cnt <= 0):
            return True
        
        return 9*abs(cnt)//2 != abs(diff)