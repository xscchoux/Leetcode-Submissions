"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution(object):
    def flatten(self, head):
        """
        :type head: Node
        :rtype: Node
        """
# DFS
        if not head:
            return None
        
        dummy = self.new = Node(-1)
        self.pre = None
        curr = head
        
        def dfs(curr):
            while curr:
                self.new.next = Node(curr.val)
                if self.pre:
                    self.new.prev = self.pre
                self.pre = self.new
                self.new = self.new.next
                if curr.child:
                    dfs(curr.child)
                curr = curr.next
        dfs(curr)
        
        self.new.prev = self.pre

        dummy.next.prev = None
        
        return dummy.next
    
# Stack
        if not head:
            return None
        
        dummyHead = Node(0, None, head, None)
        prevHead = dummyHead
        stack = []
        stack.append(head)
        
        while stack:
            currHead = stack.pop()
            prevHead.next = currHead
            currHead.prev = prevHead
            
            if currHead.next:
                stack.append(currHead.next)
                
            if currHead.child:
                stack.append(currHead.child)
                currHead.child = None
                
            prevHead = currHead
            
        dummyHead.next.prev = None
        
        return dummyHead.next