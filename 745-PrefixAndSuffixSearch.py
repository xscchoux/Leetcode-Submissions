class WordFilter(object):

# hashmap 
# Space complexity: O(N*L^3) (We have N words, and a word with length L has L^2 keys, each with length O(L))
# Time complexity: O(N*L^3) + O(Q*L) (Q:number of queries)
    def __init__(self, words):
        """
        :type words: List[str]
        """
        index = 0
        self.hmap = dict()
        for word in words:
            n = len(word)
            prefix = ['']*(n+1)
            suffix = ['']*(n+1)
            for i in range(1,n+1):
                prefix[i] = prefix[i-1] + word[i-1]
                suffix[i] = word[n-i] + suffix[i-1]
            
            for i in range(len(prefix)):
                for j in range(len(suffix)):
                    self.hmap[prefix[i]+'_'+suffix[j]] = index
            index+=1

    def f(self, prefix, suffix):
        """
        :type prefix: str
        :type suffix: str
        :rtype: int
        """
        # print(self.hmap)
        key = prefix+"_"+suffix
        if key not in self.hmap:
            return -1
        else:
            print(key)
            return self.hmap[key]


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)