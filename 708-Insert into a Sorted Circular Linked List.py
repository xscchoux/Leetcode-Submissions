"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, next=None):
        self.val = val
        self.next = next
"""

class Solution(object):
    def insert(self, head, insertVal):
        """
        :type head: Node
        :type insertVal: int
        :rtype: Node
        """
        if not head:
            newNode = Node(insertVal, None)
            newNode.next = newNode
            return newNode

        start = head
        
        while True:
            if head.val > head.next.val:  # descending
                if insertVal > head.val or insertVal < head.next.val:
                    break
            elif head.val < head.next.val:  # ascending
                if head.val <= insertVal <= head.next.val:
                    break
            if head.next == start:
                break
            head = head.next
        
# insert
        tmp = head.next
        newNode = Node(insertVal, None)
        head.next = newNode
        newNode.next = tmp
        
        return start