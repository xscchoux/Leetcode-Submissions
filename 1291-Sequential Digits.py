class Solution(object):
    def sequentialDigits(self, low, high):
        """
        :type low: int
        :type high: int
        :rtype: List[int]
        """
        candidate = "123456789"
        N = 9
        res = []
        
        for length in range(len(str(low)), len(str(high))+1):
            for start in range(0, N-length+1):
                currNum = int(candidate[start:start+length])
                if low<=currNum<=high:
                    res.append(currNum)
                elif currNum > high:
                    break
        
        return res