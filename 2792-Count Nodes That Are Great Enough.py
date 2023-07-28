# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countGreatEnoughNodes(self, root: Optional[TreeNode], k: int) -> int:
        # merge sort
        
        self.res = 0
        
        def dfs(node):
            if not node:
                return []
            
            arr = []
            leftArr = dfs(node.left)
            rightArr = dfs(node.right)
            
            i1 = i2 = 0
            put = False
            while (i1+i2) <= k and  (i1 < len(leftArr) or i2 < len(rightArr)):
                if i1 == len(leftArr):
                    if not put and rightArr[i2] >= node.val :
                        arr.append(node.val)
                        put = True
                    arr.append(rightArr[i2])
                    i2 += 1
                elif i2 == len(rightArr):
                    if not put and leftArr[i1] >= node.val :
                        arr.append(node.val)
                        put = True
                    arr.append(leftArr[i1])
                    i1 += 1
                else:
                    if leftArr[i1] <= rightArr[i2]:
                        if not put and leftArr[i1] >= node.val :
                            arr.append(node.val)
                            put = True
                        arr.append(leftArr[i1])
                        i1 += 1
                    else:
                        if not put and rightArr[i2] >= node.val :
                            arr.append(node.val)
                            put = True
                        arr.append(rightArr[i2])
                        i2 += 1
            if not put and len(arr) < k:
                arr.append(node.val)
            if len(arr) >= k and arr[k-1] < node.val:
                self.res += 1
            return arr[:k]
        
        dfs(root)
        
        return self.res