class StockSpanner(object):

    def __init__(self):
        self.stack = []

    def next(self, price):
        """
        :type price: int
        :rtype: int
        """
        weight = 1
        while self.stack and price >= self.stack[-1][0]:
            weight += self.stack.pop()[1]
        self.stack.append((price, weight))
        return weight

# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)