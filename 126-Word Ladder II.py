class Solution(object):
    def findLadders(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: List[List[str]]
        """
# BFS solution (create a dictionary at each layer)        

        layer = collections.defaultdict(list)
        layer[beginWord] = [[beginWord]]
        wordSet = set(wordList)
        if beginWord in wordSet:
            wordSet.remove(beginWord)
        
        while layer:
            newLayer = collections.defaultdict(list)
            for currWord in layer.keys():
                for i in range(len(currWord)):
                    for char in "abcdefghijklmnopqrstuvwxyz":
                        newWord = currWord[:i] + char + currWord[i+1:]
                        if newWord in wordSet:
                            newLayer[newWord] += [ prev + [newWord] for prev in layer[currWord] ]
            wordSet -= set(newLayer.keys())
            if endWord in newLayer:
                return newLayer[endWord]
            layer = newLayer
            
        return []
    
# BFS + DFS (create a graph using BFS then DFS)

        graph = collections.defaultdict(list)
        queue = [beginWord]
        wordSet = set(wordList)
        if beginWord in wordSet:
            wordSet.remove(beginWord)
        
        # create a graph
        while queue:
            used = set()
            for _ in range(len(queue)):
                currWord = queue.pop()
                for i in range(len(currWord)):
                    for char in "abcdefghijklmnopqrstuvwxyz":
                        newWord = currWord[:i] + char + currWord[i+1:]
                        if newWord in wordSet:
                            graph[currWord].append(newWord)
                            used.add(newWord)

            queue = list(used)
            wordSet -= used
        
        # DFS
        self.maxLevel = float('inf')
        res = []
        def dfs(word, path):
            if word == endWord:
                res.append(path)
                return
            for nxt in graph[word]:
                dfs(nxt, path + [nxt])
        dfs(beginWord, [beginWord])
        
        return res