class Solution(object):
    def longestConsecutive(self, nums):

# https://www.youtube.com/watch?v=rc2QdQ7U78I&t=456s
# Sol 1:

        hmap = dict()
        for num in nums:
            if num in hmap:
                continue
            left = hmap[num-1] if num-1 in hmap else 0
            right = hmap[num+1] if num+1 in hmap else 0

            if (left > 0 and right > 0):
                hmap[num] = hmap[num-left] = hmap[num + right] = left + right + 1
            elif left > 0:
                hmap[num] = hmap[num - left] = left + 1
            elif right > 0:
                hmap[num] = hmap[num + right] = right + 1
            else:
                hmap[num] = 1
        res = 0
        for val in hmap.values():
            res = max(res, val)

        return res


# Sol 2:
        hset = set(nums)
        res = 0
        for num in nums:
            if (num-1 not in hset):
                l = 1
                while (num+1 in hset):
                    l += 1
                    num += 1
                res = max(res, l)
        return res



# old solutions

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