class Solution(object):
    def findInteger(self, k, digit1, digit2):
        """
        :type k: int
        :type digit1: int
        :type digit2: int
        :rtype: int
        """
        
# generate all possible numbers O(2^11)
        limit = 2147483647
        nums = []
        
        def dfs(num, picked):
            if picked > 10:
                return 
            if 1 <= picked <= 10:
                nums.append(int(num))
                
            dfs(num+str(digit1), picked+1)
            dfs(num+str(digit2), picked+1)
        dfs("", 0)
        
        nums.sort()

        for num in nums:
            if num > limit:
                break
            if num > k  and num%k == 0:
                return num
            
        return -1
    
# BFS
        
        if digit2 < digit1:
            digit1, digit2 = digit2, digit1
            
        queue = collections.deque([digit1, digit2])
        limit = 2147483647
        
        while queue:
            curr = queue.popleft()
            if 0 < curr <= limit:
                if curr > k and curr%k == 0:
                    return curr
                queue.append(10*curr + digit1)
                queue.append(10*curr + digit2)
                
        return -1