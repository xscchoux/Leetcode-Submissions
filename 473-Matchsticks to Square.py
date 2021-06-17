class Solution(object):
    def makesquare(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        
# DFS
        if len(nums) < 4:
            return False
        
        tot = sum(nums)
        if tot%4:
            return False
        
        nums.sort(reverse=True)
        N = len(nums)
        sideLen = tot//4
        side_buckets = [0]*4
                
        def dfs(index):
            if index == N:
                return side_buckets[0] == side_buckets[1] == side_buckets[2] == sideLen
            for i in range(4):
                if side_buckets[i] + nums[index] <= sideLen:
                    side_buckets[i] += nums[index]
                    if dfs(index+1):
                        return True
                    side_buckets[i] -= nums[index]
            return False
        
        return dfs(0)
    
# DFS + memo (bitmask)
        
        if len(nums) < 4:
            return False
        
        tot = sum(nums)
        if tot%4:
            return False
        
        N = len(nums)
        sideLen = tot//4
        side_buckets = [0]*4
        memo = {}
        
        def dp(bitmask, remain, completed):
            if bitmask == 0 and completed == 4:
                return True
            if (bitmask, remain, completed) in memo:
                return memo[(bitmask, remain, completed)]
            
            ans = False
            for i in range(len(nums)):
                if bitmask & (1<<i) and nums[i] <= remain:
                    if remain - nums[i] > 0:
                        if dp(bitmask^(1<<i), remain-nums[i], completed ):
                            ans = True
                            break
                    else:
                        if dp( bitmask^(1<<i), sideLen, completed+1):
                            ans = True
                            break
            memo[(bitmask, remain, completed)] = ans
            return ans
                
        return dp((1<<N)-1, sideLen, 0)