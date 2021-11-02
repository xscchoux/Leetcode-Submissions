class Solution(object):
    def areSentencesSimilarTwo(self, sentence1, sentence2, similarPairs):
        """
        :type sentence1: List[str]
        :type sentence2: List[str]
        :type similarPairs: List[List[str]]
        :rtype: bool
        """
        if len(sentence1) != len(sentence2):
            return False
        
        parent = dict()
        for start, end in similarPairs:
            parent[start] = start
            parent[end] = end
        
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(a, b):
            pa, pb = find(a), find(b)
            parent[pa] = pb
        
        for start, end in similarPairs:
            union(start, end)

        for w1, w2 in zip(sentence1, sentence2):
            if w1 == w2:
                continue
            else:
                if w1 not in parent or w2 not in parent or find(w1) != find(w2):
                    return False
        
        return True