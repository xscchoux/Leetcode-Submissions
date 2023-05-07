class Solution:
    def colorTheArray(self, n: int, queries: List[List[int]]) -> List[int]:
        nums = [0]*n
        adj = 0
        res = []
        
        for ind, color in queries:
            if nums[ind] == 0:
                if ind > 0 and color == nums[ind-1]:
                    adj += 1
                if ind < n-1 and color == nums[ind+1]:
                    adj += 1
            else:
                if ind > 0 and nums[ind] == nums[ind-1]:
                    adj -= 1
                if ind < n-1 and nums[ind] == nums[ind+1]:
                    adj -= 1
                if ind > 0 and color == nums[ind-1]:
                    adj += 1
                if ind < n-1 and color == nums[ind+1]:
                    adj += 1
                
            nums[ind] = color
            res.append(adj)
        
        return res