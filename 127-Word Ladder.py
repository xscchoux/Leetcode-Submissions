class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
# BFS, O(M*M*N), M:length of word, N: length of wordList
        wordSet = set(wordList)
        
        if beginWord in wordList:
            wordSet.remove(beginWord)
        
        queue = collections.deque([beginWord])
        
        step = 1
        
        while queue:
            for _ in range(len(queue)):
                currWord = queue.popleft()
                if currWord == endWord:
                    return step
                for i in range(len(currWord)):
                    for char in "abcdefghijklmnopqrstuvwxyz":
                        newWord = currWord[:i] + char + currWord[i+1:]
                        if newWord in wordSet:
                            wordSet.remove(newWord)
                            queue.append(newWord)
            step += 1
        return 0
    
# bidirectional BFS
        wordSet = set(wordList)
        
        if beginWord in wordList:
            wordSet.remove(beginWord)
        if endWord not in wordList:
            return 0
        
        queue1 = set([beginWord])
        queue2 = set([endWord])
        
        step = 1
        
        while queue1 and queue2:
            if len(queue1) > len(queue2):
                queue1, queue2 = queue2, queue1
            tmp = set()
            for currWord in queue1:
                for i in range(len(currWord)):
                    for char in "abcdefghijklmnopqrstuvwxyz":
                        newWord = currWord[:i] + char + currWord[i+1:]
                        if newWord in queue2:
                            return step+1
                        if newWord in wordSet:
                            wordSet.remove(newWord)
                            tmp.add(newWord)
            queue1 = tmp
            step += 1
            
        return 0