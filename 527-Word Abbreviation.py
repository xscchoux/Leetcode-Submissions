# https://leetcode.com/problems/word-abbreviation/discuss/840471/Clean-Trie-Python-Solution
class TrieNode:
    def __init__(self):
        self.children = collections.defaultdict(list)
        self.count = 0

class Solution(object):
    def wordsAbbreviation(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        
        def createAbbr(string, i):
            if len(string) - 1 - i > 1:
                return string[:i] + str(len(string)-i-1) + string[-1]
            else:
                return string
            
        word2abbr = collections.defaultdict(list)
        res = collections.defaultdict(str)
        
        for word in words:
            word2abbr[createAbbr(word, 1)].append(word)
        for abbr, wordGroup in word2abbr.items():
            if len(wordGroup) > 1:
                # put word in the trie
                root = TrieNode()
                for word in wordGroup:
                    node = root
                    for w in word:
                        if w not in node.children:
                            node.children[w] = TrieNode()
                        node = node.children[w]
                        node.count += 1
                        
                # find where node.count == 1 for each word
                for word in wordGroup:
                    node = root
                    for ind, w in enumerate(word):
                        node = node.children[w]
                        if node.count == 1:
                            res[word] = createAbbr(word, ind+1)
                            break
                
            else:
                res[wordGroup[0]] = abbr
                
        return [res[word] for word in words]