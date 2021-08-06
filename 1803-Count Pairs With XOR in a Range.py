class TrieNode:
    def __init__(self):
        self.cnt = 0
        self.children = [None, None]

class Solution(object):
    def countPairs(self, nums, low, high):
        """
        :type nums: List[int]
        :type low: int
        :type high: int
        :rtype: int
        """
# bitwise Trie
        # 2*10^4 = 2^m => m = 14.2877....
        length = 14
        root = TrieNode()

        def countSmaller(num, limit):
            node = root
            count = 0
            for j in range(length, -1, -1):
                numbit = (num>>j)&1
                limitbit = (limit>>j)&1
                
                if limitbit == 1:
                    if node.children[numbit]:
                        count += node.children[numbit].cnt
                    node = node.children[1-numbit]
                else:
                    node = node.children[numbit]
                if not node:
                    break
            return count
        
        def insert(num):
            node = root
            for j in range(length, -1, -1):
                numbit = (num>>j) & 1
                if not node.children[numbit]:
                    node.children[numbit] = TrieNode()
                node = node.children[numbit]
                node.cnt += 1
        
        res = 0
        for num in nums:
            res += countSmaller(num, high+1) - countSmaller(num, low)
            insert(num)
            
        return res      