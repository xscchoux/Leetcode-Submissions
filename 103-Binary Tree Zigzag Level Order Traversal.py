class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        reverse = False
        queue = collections.deque([root])
        res = []
        while queue:
            nxt = collections.deque()
            for _ in range(len(queue)):
                curr = queue.popleft()
                if reverse:
                    nxt.appendleft(curr.val)
                else:
                    nxt.append(curr.val)
                if curr.left:
                    queue.append(curr.left)
                if curr.right:
                    queue.append(curr.right)
            
            res.append(nxt)
            reverse = not reverse
        return res