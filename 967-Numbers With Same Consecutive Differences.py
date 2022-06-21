class Solution(object):
    def numsSameConsecDiff(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        queue = [i for i in range(1, 10)]
        N = 1
        while N < n:
            nxt_queue = []
            length = len(queue)
            for i in range(length):
                num = queue.pop()
                digit = num%10
                for nxt in set([digit-k, digit+k]):
                    if 0<=nxt<=9:
                        nxt_queue.append(num*10+nxt)
            N+=1
            queue = nxt_queue
        return queue