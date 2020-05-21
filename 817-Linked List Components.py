# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def numComponents(self, head, G):
        """
        :type head: ListNode
        :type G: List[int]
        :rtype: int
        """
# Time: O(N + G.length)
# Space: O(G.length)
        
        res = 0
        setG = set(G)
        dummy = ListNode(None)
        dummy.next = head
        appear = False
        
        while dummy:
            if dummy.val in setG:
                setG.remove(dummy.val)
                if not appear:
                    res += 1
                    appear = True
            else:
                appear = False
            dummy = dummy.next
        
        return res