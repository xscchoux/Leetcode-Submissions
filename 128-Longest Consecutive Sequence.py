class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        numbers = set(nums)
        res = 0
        
        for num in nums:
            length = 0
            if num in numbers:
                length += 1
                left = num - 1
                right = num + 1
                numbers.remove(num)
                
                while left in numbers:
                    numbers.remove(left)
                    length += 1
                    left -= 1
                    
                    
                while right in numbers:
                    numbers.remove(right)
                    length += 1
                    right += 1
                    
            if length > res:
                res = length
                
        return res
        
        

        
# https://www.cnblogs.com/grandyang/p/4276225.html
#         num_set = set(nums)
#         res = 0        
#         for num in nums:

#             if num not in num_set:
#                 continue
#             num_set.remove(num)
#             prev_num = num - 1
#             next_num = num + 1
#             while prev_num in num_set:
#                 num_set.remove(prev_num)
#                 prev_num -= 1
            
#             while next_num in num_set:
#                 num_set.remove(next_num)
#                 next_num += 1

#             res = max(res,next_num - prev_num - 1)
#         return res