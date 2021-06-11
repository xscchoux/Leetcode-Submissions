class TrieNode:
    def __init__(self):
        self.children = dict()

class Solution(object):
    def findMaximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
#O(32*n), Bitwise Trie
        root = TrieNode()
        L = len(bin(max(nums))) - 2
        res = 0
        
        for num in nums:
            head = root
            xor_head = root
            tmp = 0
            for i in range(L, -1, -1):
                
                curr = (num >> i) & 1
                
                if curr not in head.children:
                    head.children[curr] = TrieNode()
                head = head.children[curr]
                
                if curr^1 in xor_head.children:
                    xor_head = xor_head.children[curr^1]
                    tmp += 1 << i
                else:
                    xor_head = xor_head.children[curr]
            res = max(res, tmp)
        
        return res

# O(32*n)
# https://blog.csdn.net/fuxuemingzhu/article/details/79473171
# a ^ b = x   =>   a ^ x = b

        if len(nums) == 1:
            return 0
        
        res = mask = 0
        
        for i in range(32)[::-1]:
            mask += 1<<i
            prefixSet = set([num&mask for num in nums])
            
            tmp = res | 1<<i
            for prefix in prefixSet:
                if tmp^prefix in prefixSet:
                    res = tmp
                    break
        return res