class Solution(object):
    def numTilePossibilities(self, tiles):
        """
        :type tiles: str
        :rtype: int
        """
        tiles = sorted(list(tiles))
        
        used = [False]*len(tiles)
        res = []
        string = ""
        
        def dfs(string):
            res.append(string)
            for i in range(len(tiles)):
                if i>0 and tiles[i] == tiles[i-1] and not used[i-1]:
                    continue
                if not used[i]:
                    used[i] = True
                    dfs(string+tiles[i])
                    used[i] = False
        dfs(string)
        return len(res) - 1