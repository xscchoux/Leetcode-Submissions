class Solution(object):
    def validateBinaryTreeNodes(self, n, leftChild, rightChild):
        """
        :type n: int
        :type leftChild: List[int]
        :type rightChild: List[int]
        :rtype: bool
        """
        nodeVal = set()
        
        for l,r in zip(leftChild, rightChild):
            nodeVal.add(l)
            nodeVal.add(r)
        
        # find root node
        root = None
        for i in range(n):
            if i not in nodeVal:
                root = i
                break
                
        if root == None:
            return False
        
        # return False if there's a cycle
        queue = collections.deque([root])
        visited = set([root])
        while queue:
            for _ in range(len(queue)):
                curr = queue.popleft()
                l, r = leftChild[curr], rightChild[curr]
                if l != -1:
                    if l not in visited:
                        visited.add(l)
                        queue.append(l)
                    else:
                        return False
                if r != -1:
                    if r not in visited:
                        visited.add(r)
                        queue.append(r)
                    else:
                        return False
                    
        return len(visited) == n