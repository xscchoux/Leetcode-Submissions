# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# https://www.youtube.com/watch?v=3dXUj5fGLXI
import random
class Solution(object):

    def __init__(self, head):
        """
        @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
        :type head: ListNode
        """
        self.head = head

    def getRandom(self):
        """
        Returns a random node's value.
        :rtype: int
        """
        curr = self.head
        reservoir = 1
        res = 0
        
        while curr:
            index = random.randrange(reservoir)
            if index == 0:
                res = curr.val
            curr = curr.next
            reservoir += 1
        
        return res

# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()