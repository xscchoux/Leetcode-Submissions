class TrieNode:
    def __init__(self):
        self.children = dict()
        self.val = float('-inf') 

class Solution:
    def maximumStrongPairXor(self, nums: List[int]) -> int:
        # x <= 2*y
        nums.sort()
        res = 0
        
        root = TrieNode()
        
        for num in nums:
            node = root
            for i in range(19, -1, -1):
                val = (num >> i)&1
                if val not in node.children:
                    node.children[val] = TrieNode()
                node = node.children[val]
                node.val = num

            currMax = 0
            
            node = root
            for i in range(19, -1, -1):
                val = (num >> i)&1
                optimal = val^1
                if optimal in node.children and 2*node.children[optimal].val >= num:
                    node = node.children[optimal]
                    currMax += (1<<i)
                else:
                    node = node.children[val]
            
            res = max(res, currMax)
            
        return res