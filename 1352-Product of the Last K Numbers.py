# solution from lee215

class ProductOfNumbers(object):

    def __init__(self):
        self.preProduct = [1]

    def add(self, num):
        """
        :type num: int
        :rtype: None
        """
        if num == 0:
            self.preProduct = [1]
        else:
            self.preProduct.append(self.preProduct[-1]*num)

    def getProduct(self, k):
        """
        :type k: int
        :rtype: int
        """
        if k >= len(self.preProduct):
            return 0
        else:
            return self.preProduct[-1]/self.preProduct[-k-1]


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)