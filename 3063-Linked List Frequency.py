# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def frequenciesOfElements(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = head;
        freqMap = defaultdict(ListNode) # value of node : ListNode(freq count, previous node)
        prev = None
        
        while curr:
            if (x:=curr.val) in freqMap:
                node = freqMap[x]
                node.val += 1
            else:
                newNode = ListNode(1, prev)
                freqMap[x] = newNode
                prev = newNode
            curr = curr.next

        return prev