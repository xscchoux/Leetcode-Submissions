class Bucket:
    def __init__(self):
        self.element = []
    def getValue(self, key):
        for k, v in self.element:
            if k == key:
                return v
        return -1
    def putValue(self, key, value):
        found = False
        for ind, element in enumerate(self.element):
            if element[0] == key:
                found = True
                self.element[ind] = (key, value)
                break
        if not found:
            self.element.append((key, value))
    def delete(self, key):
        for ind, element in enumerate(self.element):
            if key == element[0]:
                self.element.pop(ind)
                break
        
class MyHashMap(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.bucketNum = 1033
        self.hashmap = [Bucket() for _ in range(self.bucketNum)]

    def put(self, key, value):
        """
        value will always be non-negative.
        :type key: int
        :type value: int
        :rtype: None
        """
        hashNum = key%self.bucketNum
        self.hashmap[hashNum].putValue(key, value)

    def get(self, key):
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        :type key: int
        :rtype: int
        """
        hashNum = key%self.bucketNum
        return self.hashmap[hashNum].getValue(key)

    def remove(self, key):
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        :type key: int
        :rtype: None
        """
        hashNum = key%self.bucketNum
        self.hashmap[hashNum].delete(key)


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)