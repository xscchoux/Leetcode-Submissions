class Solution(object):
    def maxLength(self, arr):
        """
        :type arr: List[str]
        :rtype: int
        """
        self.res = 0
        
        def backtracking(start, string):
            self.res = max(self.res, len(string))
            
            for i in range(start, len(arr)):
                if len(string+arr[i]) == len(set(string+arr[i])):
                    backtracking(i+1, string+arr[i])
        
        backtracking(0, '')
        
        return self.res