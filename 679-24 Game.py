class Solution(object):
    def judgePoint24(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        
        def find24(arr):
            n = len(arr)
            if n == 1:
                return abs(arr[0] - 24.0) < 0.001
            
            for i in range(n-1):
                for j in range(i+1,n):
                    newArr = arr[:i] + arr[i+1:j] + arr[j+1:]
                    
                    if find24(newArr + [arr[i] + arr[j]]):
                        return True
                    if find24(newArr + [arr[i] - arr[j]]):
                        return True
                    if find24(newArr + [arr[j] - arr[i]]):
                        return True
                    if find24(newArr + [arr[i] * arr[j]]):
                        return True
                    
                    if arr[i] != 0 and find24(newArr + [float(arr[j])/float(arr[i])]):
                        return True
                    if arr[j] != 0 and find24(newArr + [float(arr[i])/float(arr[j])]):
                        return True
                    
            return False
        
        return find24(nums)