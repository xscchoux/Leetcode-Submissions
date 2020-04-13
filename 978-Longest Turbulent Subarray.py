class Solution(object):
    def maxTurbulenceSize(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        
# brute force O(n^2), TLE
#         if not A:
#             return 0
#         _max = 1
        
#         for i in range(len(A)-1):
#             res = 1
#             boolean = True
#             prev = A[i]
#             for j in range(i+1, len(A)):
#                 if boolean:
#                     if prev > A[j]:
#                         res += 1
#                         prev = A[j]
#                     else:
#                         break
#                 else:
#                     if prev < A[j]:
#                         res += 1
#                         prev = A[j]
#                     else:
#                         break
#                 boolean = not boolean
#             _max = max(res, _max)
            
#         for i in range(len(A)-1):
#             res = 1
#             boolean = False
#             prev = A[i]
#             for j in range(i+1, len(A)):
#                 if boolean:
#                     if prev > A[j]:
#                         res += 1
#                         prev = A[j]
#                     else:
#                         break
#                 else:
#                     if prev < A[j]:
#                         res += 1
#                         prev = A[j]
#                     else:
#                         break
#                 boolean = not boolean
#             _max = max(res, _max)
            
#         return _max
    
# sliding window
        def compare(a, b):
            if a > b:
                return 1
            elif a == b:
                return 0
            else:
                return -1 
        res = 1
        left = 0
        for i in range(1, len(A)):
            c = compare(A[i-1], A[i])
            if c == 0:
                left += 1
                continue
            if i == len(A)-1 or c*compare(A[i],A[i+1]) != -1:
                if i-left + 1 > res:
                    res = i-left+1
                left = i  
        return res