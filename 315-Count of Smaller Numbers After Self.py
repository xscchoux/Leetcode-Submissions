# Binary Indexed Tree (Fenwick Tree)
# Time complexity: O(N*logN), Space complexity: O(N)
class BIT:
    def __init__(self, N):
        self.BITarr = [0]*(N+1)
        self.len = N+1
    
    def update(self, ind, val):
        while ind < self.len:
            self.BITarr[ind] += val
            ind += ind&(-ind)
        
    def query(self, ind):
        res = 0
        while ind > 0:
            res += self.BITarr[ind]
            ind -= ind&(-ind)
        return res

class Solution(object):
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        numSet = set(nums)
        N = len(numSet)
        BITree = BIT(N+1)
        hmap = {val:(ind+1) for ind, val in enumerate(sorted(numSet))}
        
        
        for i in range(len(nums)-1, -1, -1):
            index = hmap[nums[i]]
            nums[i] = BITree.query(index-1)
            BITree.update(index, 1)
            
        return nums

# merge sort, Time complexity:O(NlogN), Space complexity:O(N)
class Solution(object):
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        N = len(nums)
        res = [0]*N
        
        def mergeSort(arr):
            if len(arr) <= 1:
                return arr
            mid = len(arr)//2
            leftArr = mergeSort(arr[:mid])
            rightArr = mergeSort(arr[mid:])
            for i in range(len(arr))[::-1]:
                if not rightArr or (leftArr and nums[leftArr[-1]] > nums[rightArr[-1]]):
                    res[leftArr[-1]] += len(rightArr)
                    arr[i] = leftArr.pop()
                else:
                    arr[i] = rightArr.pop() 
            return arr
            
        arr = [i for i in range(len(nums))]
        mergeSort(arr)
        return res
    
    
# BST, TLE when the tree is very unbalanced => O(N^2)
# class TreeNode:
#     def __init__(self, val):
#         self.val = val
#         self.left = None
#         self.right = None
#         self.countSmaller = 0
        
# class Solution(object):
#     def countSmaller(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: List[int]
#         """
#         N = len(nums)
#         root = TreeNode(nums[-1])
#         nums[-1] = 0
        
#         for i in range(N-2, -1, -1):
#             node = root
#             count = 0
#             while True:
#                 if nums[i] < node.val:
#                     node.countSmaller += 1
#                     if node.left:
#                         node = node.left
#                     else:
#                         node.left = TreeNode(nums[i])
#                         break
#                 else:
#                     if nums[i] > node.val:
#                         count += 1
#                     count += node.countSmaller
#                     if node.right:
#                         node = node.right
#                     else:
#                         node.right = TreeNode(nums[i])
#                         break
                        
#             nums[i] = count
            
#         return nums