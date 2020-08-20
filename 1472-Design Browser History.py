class BrowserHistory(object):

    def __init__(self, homepage):
        """
        :type homepage: str
        """
        self.stack = [homepage]
        self.remain = []

    def visit(self, url):
        """
        :type url: str
        :rtype: None
        """
        self.stack.append(url)
        self.remain = []

    def back(self, steps):
        """
        :type steps: int
        :rtype: str
        """
        if steps < len(self.stack):
            self.stack, self.remain = self.stack[:-steps], self.stack[-steps:]+ self.remain
        else:
            self.stack, self.remain = [self.stack[0]], self.stack[1:] + self.remain
        return self.stack[-1]

    def forward(self, steps):
        """
        :type steps: int
        :rtype: str
        """
        if steps > len(self.remain):
            self.stack, self.remain = self.stack + self.remain, []
        else:
            self.stack, self.remain = self.stack + self.remain[:steps], self.remain[steps:]
        return self.stack[-1]


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)