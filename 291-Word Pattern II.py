class Solution(object):
    def wordPatternMatch(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        hmap = dict()
        usedString = set()
        
        
        def dfs(pattern, string, usedString):
            if not pattern:
                return not string
            
            currPattern = pattern[0]
            if currPattern in hmap:
                if hmap[currPattern] != string[0:len(hmap[currPattern])]:
                    return False
                else:
                    return dfs(pattern[1:], string[len(hmap[currPattern]):], usedString)
                
            else:
                for i in range(1,len(string)+1):
                    if string[0:i] in usedString:
                        continue
                    hmap[currPattern] = string[0:i]
                    usedString.add(string[0:i])
                    if dfs(pattern[1:], string[i:], usedString):
                        return True
                    del hmap[currPattern]
                    usedString.remove(string[0:i])
                    
                return False
            
        return dfs(pattern, str, usedString)