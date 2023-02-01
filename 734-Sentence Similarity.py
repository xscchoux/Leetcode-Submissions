class Solution:
    def areSentencesSimilar(self, sentence1: List[str], sentence2: List[str], similarPairs: List[List[str]]) -> bool:
        if len(sentence1) != len(sentence2):
            return False
        hmap = collections.defaultdict(set)
        for a, b in similarPairs:
            hmap[a].add(b)
            hmap[b].add(a)

        for a, b in zip(sentence1, sentence2):
            if a != b:
                if b not in hmap[a] and a not in hmap[b]:
                    return False
        
        return True