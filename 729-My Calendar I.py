# Brute Force, O(n^2)
class MyCalendar(object):

    def __init__(self):
        self.arr = []

    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """
        for s, e in self.arr:
            if not ( start>=e or end<=s):
                return False;
        self.arr.append((start, end))
        return True


# Interval-based BST, O(nlogn) to O(n^2)
class TreeNode:
    def __init__(self, start, end):
        self.left = None
        self.right = None
        self.start = start
        self.end = end

class MyCalendar(object):

    def __init__(self):
        self.root = None

    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """
        def insert(start, end):
            head = self.root
            while head:
                if head.end <= start:
                    if not head.right:
                        head.right = TreeNode(start, end)
                        return True
                    head = head.right
                elif head.start >= end:
                    if not head.left:
                        head.left = TreeNode(start, end)
                        return True
                    head = head.left
                else:
                    return False
            
        if not self.root:
            self.root = TreeNode(start, end)
            return True
        else:
            return insert(start, end)