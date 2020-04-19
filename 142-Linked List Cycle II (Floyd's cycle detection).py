class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
# with extra space:
        # seen = set()
        # while(head):
        #     if head in seen:
        #         return head
        #     seen.add(head)
        #     head = head.next
        # return None

        
# http://fisherlei.blogspot.com/2013/11/leetcode-linked-list-cycle-ii-solution.html
# https://www.youtube.com/watch?v=LUm2ABqAs1w
        fast = slow = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if fast == slow:
                slow = head
                break
        if not fast or not fast.next:
            return None
        while slow != fast:
            slow = slow.next
            fast = fast.next
            if slow == fast:
                break
        return slow
                