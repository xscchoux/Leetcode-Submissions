class TrieNode(object):
    def __init__(self):
        self.children = {}
        self.word = []
        
class Trie(object):
    def __init__(self):
        self.root = TrieNode()
        
    def insert(self, word):
        node = self.root
        for w in word:
            if w not in node.children:
                node.children[w] = TrieNode()
            node = node.children[w]
            node.word.append(word)
    
    def search(self, searchWord):
        node = self.root
        ans = []
        for i in range(len(searchWord)):
            if searchWord[i] in node.children:
                node = node.children[searchWord[i]]
                ans.append(sorted(node.word)[:3])
            else:
                break
        
        for i in range(len(searchWord) - len(ans)):
            ans.append([])
        return ans

class Solution(object):
    def suggestedProducts(self, products, searchWord):
        """
        :type products: List[str]
        :type searchWord: str
        :rtype: List[List[str]]
        """

        trie = Trie()
# insert products
# O(nk),  n:num of products, k: length of the product
        for product in products:
            trie.insert(product)

# searcg products
# O(k*nlogn)
        res = trie.search(searchWord)
        return res


# Solution 2
class Solution(object):
    def suggestedProducts(self, products, searchWord):
        """
        :type products: List[str]
        :type searchWord: str
        :rtype: List[List[str]]
        """
        products.sort()
        res = []
        
        prefix = ""
        for w in searchWord:
            prefix += w
            idx = bisect.bisect_left(products, prefix)
            res.append([ word for word in products[idx:idx+3] if word.startswith(prefix)])
        
        return res