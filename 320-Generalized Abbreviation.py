class Solution(object):
    def generateAbbreviations(self, word):
        """
        :type word: str
        :rtype: List[str]
        """
        self.res = []
        def dfs(index, number, curr):
            if index == len(word):
                if number!=0:
                    curr += str(number)
                self.res.append(curr)
                return
            if number > 0:
                dfs(index+1, 0, curr + str(number) + word[index])
            else:
                dfs(index+1, 0, curr+word[index])
            dfs(index+1, number+1, curr)
            
        dfs(0, 0, "")
        return self.res