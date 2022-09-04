# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import defaultdict, deque
class Solution(object):
    def verticalTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        hmap = defaultdict(lambda:defaultdict(list))
        res = []
        queue = deque([(root, 0, 0)])
        
        while queue:
            for _ in range(len(queue)):
                curr, col, row = queue.popleft()
                hmap[col][row].append(curr.val)
                if curr.left:
                    queue.append((curr.left, col-1, row+1))
                if curr.right:
                    queue.append((curr.right, col+1, row+1))

        for c in sorted(hmap.keys()):
            tmp = []
            for r in sorted(hmap[c].keys()):
                tmp.extend(sorted(hmap[c][r]))
            res.append(tmp)
        
        return res