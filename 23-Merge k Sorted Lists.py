# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

import heapq
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
# Sort all lists O(NlogN)
        res = []
        for node in lists:
            while node:
                res.append(node.val)
                node = node.next
        res.sort()
        curr = dummy = ListNode(0)
        for num in res:
            dummy.next = ListNode(num)
            dummy = dummy.next
        return curr.next
    
# priority queue O(Nlogk)
        
        curr = dummy = ListNode(0)
        minheap = []
        for node in lists:
            if node:
                heapq.heappush(minheap,(node.val, node))
        
        while minheap:
            value, node = heapq.heappop(minheap)
            curr.next = node
            curr = curr.next
            if curr.next:
                heapq.heappush(minheap, (curr.next.val, curr.next))
                
        return dummy.next

# Merge with Divide And Conquer O(Nlogk)
        
        def merge2list(l1, l2):
            dummy = curr = ListNode(0)
            while l1 and l2:
                if l1.val > l2.val:
                    curr.next = l2
                    l2 = l2.next
                else:
                    curr.next = l1
                    l1 = l1.next  
                curr = curr.next
            if l2:
                curr.next = l2
            else:
                curr.next = l1
            dummy2 = dummy
            while dummy2:
                dummy2 = dummy2.next
            return dummy.next
        
        def mergeAll(lists, l, r):
            if l>r:
                return None
            elif l == r:
                return lists[l]
            elif l + 1 == r:
                return merge2list(lists[l], lists[r])
            else:
                mid = l + (r-l)//2
                left = mergeAll(lists, l, mid)
                right = mergeAll(lists, mid+1, r)
                return merge2list(left, right)

        return mergeAll(lists, 0, len(lists)-1)