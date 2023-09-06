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


# Without creating new linked-lists
        count = 0
        curr = head
        while curr:
            count += 1
            curr = curr.next
        
        q, r = divmod(count, k)
        res = []
        curr = head
        
        for i in range(k):
            if not curr:
                res.append(None)
                continue
            h = curr
            for step in range(q + (i < r) -1):
                curr = curr.next
            tmp = curr.next
            curr.next = None
            curr = tmp
            res.append(h)
        
        return res