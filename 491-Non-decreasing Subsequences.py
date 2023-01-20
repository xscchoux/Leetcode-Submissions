class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        
# Maybe faster

#         res = set()
        
#         def dfs(ind, val):
#             nonlocal res
#             if ind == len(nums):
#                 if len(val) > 1:
#                     res.add(tuple(nums[i] for i in val))
#                 return
#             dfs(ind+1, val)
#             if not val:
#                 dfs(ind+1, val+[ind])
#             elif nums[val[-1]] <= nums[ind]:
#                 if nums[ind] == nums[ind-1]:
#                     if ind - val[-1] == 1:
#                         dfs(ind+1, val+[ind])
#                 else:
#                     dfs(ind+1, val+[ind])
#         dfs(0, [])
#         return res

# O(n*2^n)
        res = set()
        
        def dfs(ind, val):
            nonlocal res
            if ind == len(nums):
                if len(val) > 1:
                    res.add(tuple(x for x in val))
                return
            
            dfs(ind+1, val)
            if not val or val[-1] <= nums[ind]:
                dfs(ind+1, val + [nums[ind]])    
            
        dfs(0, [])
        return res