class Solution(object):
    def deckRevealedIncreasing(self, deck):
        """
        :type deck: List[int]
        :rtype: List[int]
        """
        n = len(deck)
        queue = collections.deque(range(n))
        res = [None]*n
        
        for card in sorted(deck):
            res[queue.popleft()] = card
            if queue:
                queue.append(queue.popleft())
                
        return res