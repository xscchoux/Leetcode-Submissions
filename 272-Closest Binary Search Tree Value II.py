# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import heapq
class Solution(object):
    def closestKValues(self, root, target, k):
        """
        :type root: TreeNode
        :type target: float
        :type k: int
        :rtype: List[int]
        """
# recursive solution (inorder traversal + binary search)
        stack = []
        def inorder(root):
            if not root:
                return
            inorder(root.left)
            stack.append(root.val)
            inorder(root.right)
        inorder(root)
        
        # binary search (find the first element : stack[index] >= target)
        left, right = 0, len(stack)-1
        while left + 1 < right:
            mid = left + (right-left)//2
            if stack[mid]< target:
                left = mid
            else:
                right = mid
        
        if stack[left] >= target:
            index = left
        else:
            index = right
            
        
        # search k elements
        res = []
        l , r = index-1, index
        while k > 0:
            if l>=0 and r<len(stack):
                if abs(stack[l] - target) < (stack[r] - target):
                    res.append(stack[l])
                    l-=1
                else:
                    res.append(stack[r])
                    r+=1
            elif l>=0:
                res.append(stack[l])
                l-=1
            elif r<len(stack):
                res.append(stack[r])
                r+=1
            k-=1
        return res
        
# recursive solution (compare while recursion)

        stack = []
        def dfs(root, target):
            if not root:
                return
            dfs(root.left, target)
            if len(stack) < k:
                stack.append(root.val)
            else:
                if abs(root.val - target) < abs(stack[0] - target):
                    stack.append(root.val)
                    stack.pop(0)
            dfs(root.right, target)
        dfs(root, target)
        return stack
    
# iterative solution (compare while iteration)
        res = []
        stack = []
        while True:
            if root:
                stack.append(root)
                root = root.left
            elif stack:
                root = stack.pop()
                if len(res) < k:
                    res.append(root.val)
                else:
                    if abs(root.val-target) < abs(res[0]-target):
                        res.append(root.val)
                        res.pop(0)
                root = root.right
            else:
                break
        return res
    
# use heap and recursion

        maxheap = []
        def inorder(root):
            if not root:
                return
            inorder(root.left)
            heapq.heappush(maxheap,(-abs(root.val-target), root.val))
            if len(maxheap) > k:
                heapq.heappop(maxheap)
            inorder(root.right)   
        inorder(root)
        res = []
        for diff, val in maxheap:
            res.append(val)
        return res
        