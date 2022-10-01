class LUPrefix(object):

    def __init__(self, n):
        """
        :type n: int
        """
        self.arr = [False]*(n+1)
        self.res = 0

    def upload(self, video):
        """
        :type video: int
        :rtype: None
        """
        self.arr[video] = True
        while self.res + 1 < len(self.arr) and self.arr[self.res+1]:
            self.res += 1

    def longest(self):
        """
        :rtype: int
        """
        return self.res


# Your LUPrefix object will be instantiated and called as such:
# obj = LUPrefix(n)
# obj.upload(video)
# param_2 = obj.longest()