from collections import defaultdict,deque
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def distanceK(self, root, target, K):
        """
        :type root: TreeNode
        :type target: TreeNode
        :type K: int
        :rtype: List[int]
        """
# time complexity: O(N), space complexity: O(N)
# build a graph O(N)

        graph = defaultdict(list)
        def buildGraph(root, parent):
            if not root:
                return
            graph[root.val].append(parent.val)
            graph[parent.val].append(root.val)
            buildGraph(root.left, root)
            buildGraph(root.right, root)
        dummy = TreeNode(-1)
        buildGraph(root, dummy)
            
# perform BFS  O(N)
        queue = deque([target.val])
        seen = set()
        seen.add(target.val)
        seen.add(-1)

        while queue and K>0:
            size = len(queue)
            for _ in range(size):
                currNode = queue.popleft()
                for childNode in graph[currNode]:
                    if childNode not in seen:
                        queue.append(childNode)
                        seen.add(childNode) 
            K-=1
        return list(queue)