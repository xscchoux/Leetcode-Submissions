class Solution(object):
    def threeSumMulti(self, arr, target):
        """
        :type arr: List[int]
        :type target: int
        :rtype: int
        """
# Two pointer
#         arr.sort()
#         res = 0
#         for i in range(len(arr)-2):
#             j = i+1
#             k = len(arr)-1
#             while j<k:
#                 if arr[j] + arr[k] < target - arr[i]:
#                     j+=1
#                 elif arr[j] + arr[k] > target - arr[i]:
#                     k-=1
#                 else:
#                     left, right = 1, 1
#                     while j + left < k and arr[j] == arr[j+left]:
#                         left+=1
#                     j = j+left-1
                    
#                     while k-right > j and arr[k] == arr[k-right]:
#                         right+=1
#                     k = k-right+1
                    
#                     if arr[j] == arr[k]:
#                         res += (left + right)*(left+right-1)//2
#                     else:
#                         res += left*right
#                     j+=1
#                     k-=1
        
#         return res % (10**9 + 7)
    
# HashMap

#         hmap = dict()
#         count = 0
        
#         for i in range(1,len(arr)):
#             if target - arr[i] in hmap:
#                 count = (count + hmap[target-arr[i]])%(10**9+7)
#             for j in range(i):
#                 hmap[arr[i]+arr[j]] = hmap.get(arr[i]+arr[j], 0) + 1
        
#         return count
    
# HashMap2

        hmap = dict()
        count = 0
        
        for char in arr:
            hmap[char] = hmap.get(char, 0) + 1
            
        for num1 in hmap.keys():
            for num2 in hmap.keys():
                num3 = target - num1 - num2
                if num3 not in hmap:
                    continue
                if num1 == num2 and num2 == num3:
                    count += hmap[num1]*(hmap[num1]-1)*(hmap[num1]-2)//6
                elif num1 == num2:
                    count += hmap[num3]*hmap[num1]*(hmap[num1]-1)//2
                elif num1 < num2 and num2 < num3:
                    count += hmap[num1]*hmap[num2]*hmap[num3]
        
        return count % (10**9 + 7)