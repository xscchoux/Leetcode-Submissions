class Solution(object):
    def maximumSwap(self, num):
        """
        :type num: int
        :rtype: int
        """
        A = map(int, str(num))
        maxIdx = len(A) - 1
        swapSmall = swapLarge = None
        for i in range(len(A)-2, -1, -1):
            if A[i] < A[maxIdx]:
                swapSmall, swapLarge = i, maxIdx
            elif A[i] > A[maxIdx]:
                maxIdx = i
        if swapSmall != None:
            A[swapSmall], A[swapLarge] = A[swapLarge], A[swapSmall]
        
        return int("".join(map(str, A)))