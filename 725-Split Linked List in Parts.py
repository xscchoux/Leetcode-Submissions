# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def splitListToParts(self, root, k):
        """
        :type root: ListNode
        :type k: int
        :rtype: List[ListNode]
        """
        numNode = 0
        dummy = root        
        while dummy:
            dummy = dummy.next
            numNode += 1
        
        num, remainder = divmod(numNode, k)
        
        curr = root
        res = []
        for part in range(k):
            head = tmp = ListNode(None)
            for i in range(num+(part<remainder)):
                tmp.next = ListNode(curr.val)
                curr = curr.next
                tmp = tmp.next
            res.append(head.next)
        return res