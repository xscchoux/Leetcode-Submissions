import random
class RandomizedSet(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.hmap = dict()
        self.arr = []

    def insert(self, val):
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        if val in self.hmap:
            return False
        
        self.hmap[val] = len(self.arr)
        self.arr.append(val)
        
        return True
        

    def remove(self, val):
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        :type val: int
        :rtype: bool
        """
        if val not in self.hmap:
            return False
        
        index = self.hmap[val]
        self.hmap[self.arr[-1]] = index
        self.arr[index], self.arr[-1] = self.arr[-1], self.arr[index]
        del self.hmap[val]
        self.arr.pop()
        return True

    def getRandom(self):
        """
        Get a random element from the set.
        :rtype: int
        """
        index = random.randrange(0, len(self.arr))
        return self.arr[index]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()