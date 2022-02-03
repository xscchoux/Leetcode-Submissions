class ExamRoom(object):

    def __init__(self, n):
        """
        :type n: int
        """
        self.occupied = []
        self.N = n

    def seat(self):
        """
        :rtype: int
        """

        if not self.occupied:
            self.occupied.append(0)
            return 0
        else:
            maxDist = self.occupied[0]
            res = 0
            for a, b in zip(self.occupied, self.occupied[1:]):
                if (b-a)//2 > maxDist:
                    maxDist, res = (b-a)//2, (b+a)//2
            if self.N - 1 - self.occupied[-1] > maxDist:
                maxDist, res = self.N - 1 - self.occupied[-1], self.N-1
            bisect.insort(self.occupied, res)
            return res

    def leave(self, p):
        """
        :type p: int
        :rtype: None
        """
        self.occupied.remove(p)