class Solution(object):
    def dailyTemperatures(self, T):
        """
        :type T: List[int]
        :rtype: List[int]
        """
# monotonic stack

        stack = []
        res = [0]*len(T)
        
        for i in range(len(T)):
            while stack and T[i] > T[stack[-1]]:
                index = stack.pop()
                res[index] = i - index
            stack.append(i)
        
        return res