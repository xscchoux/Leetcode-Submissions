"""
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
# first try:

        if not head:
            return None
        hmap = dict()
        tmp = newHead = Node(head.val, None, None)
        dummyHead = head
        
        while dummyHead:
            hmap[dummyHead] = tmp
            dummyHead = dummyHead.next
            if dummyHead:
                tmp.next = Node(dummyHead.val, None, None)
                tmp = tmp.next
        
        tmp = newHead
        
        while tmp:
            if head.random:
                tmp.random = hmap[head.random]
            else:
                tmp.random = None
            tmp = tmp.next
            head = head.next
            
        return newHead
    
# recursive solution
        hmap = dict()
    
        def recurse(node):
            if not node:
                return None
            if node in hmap:
                return hmap[node]
            copyNode = Node(node.val, None, None)
            hmap[node] = copyNode
            copyNode.next = recurse(node.next)
            copyNode.random = recurse(node.random)
            return copyNode
        
        return recurse(head)