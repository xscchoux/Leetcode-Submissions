import bisect
class Solution:
    def maximumWhiteTiles(self, tiles: List[List[int]], carpetLen: int) -> int:
        preSum = [0]
        tiles.sort(key = lambda x:x[0])
        startArr = [tile[0] for tile in tiles]
        
        res = 0
        for s, e in tiles:
            preSum.append(preSum[-1] + e-s+1)
        
        for i in range(len(tiles)):
            start, end = tiles[i]
            endPoint = min(tiles[-1][1], start+carpetLen-1)
            
            prevIdx = bisect.bisect_right(startArr, endPoint) - 1
            
            if endPoint >= tiles[prevIdx][1]:
                res = max(res, preSum[prevIdx+1] - preSum[i])
            else:
                res = max(res, preSum[prevIdx+1] - preSum[i] - ( tiles[prevIdx][1] - endPoint) )
                
        return res