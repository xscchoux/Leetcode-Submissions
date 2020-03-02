from collections import defaultdict
from collections import deque
class Solution(object):
    def alienOrder(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        
        child = defaultdict(set)
        parent = defaultdict(set)
        
        for word in words:
            for char in word:
                child[char] = set()
                parent[char] = set()
                
# construct the graph
        for word1, word2 in zip(words[:-1],words[1:]):
            if len(word1) > len(word2) and word1[:len(word2)] == word2:
                return ""          
            for char1, char2 in zip(word1, word2):
                if char1 != char2:
                    child[char1].add(char2)
                    parent[char2].add(char1)
                    break
        
        res = []
        queue = deque([])
        
# find characters with no parents:
        no_parent_nodes = [ node for node in parent.keys() if not parent[node]]
        for key in no_parent_nodes:
            queue.append(key)
            del parent[key]

# topology sort
        res = []
        while queue:
            node = queue.popleft()
            res.append(node)
            for childNode in child[node]:
                parent[childNode].remove(node)
                if not parent[childNode]:
                    del parent[childNode]
                    queue.append(childNode)
        if not parent:
            return "".join(res)
        else:
            return ""