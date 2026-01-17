# https://leetcode.cn/problems/separate-squares-ii/solutions/3078402/lazy-xian-duan-shu-sao-miao-xian-pythonj-eeqk/
from sortedcontainers import SortedList
class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        totArea = 0
        hmap = defaultdict(list)

        for x, y, side in squares:
            hmap[y].append((1, x, x+side))
            hmap[y+side].append((0, x, x+side))


        def calBaseLength(sl):
            rightSoFar = 0
            baseLength = 0
            
            for xLeft, xRight in sl:
                if xRight > rightSoFar:
                    baseLength += xRight - max(xLeft, rightSoFar)
                    rightSoFar = xRight
            
            return baseLength

        sl = SortedList()
        for y1, y2 in pairwise(sorted(hmap)):
            for flag, xLeft, xRight in hmap[y1]:
                if flag:
                    sl.add((xLeft, xRight))
                else:
                    sl.remove((xLeft, xRight))
            baseLen = calBaseLength(sl)
            totArea += baseLen*(y2-y1)

        sl.clear()
        currArea = 0
        for y1, y2 in pairwise(sorted(hmap)):
            for flag, xLeft, xRight in hmap[y1]:
                if flag:
                    sl.add((xLeft, xRight))
                else:
                    sl.remove((xLeft, xRight))
            baseLen = calBaseLength(sl)
            currArea += baseLen*(y2-y1)
            if currArea*2 == totArea:
                return y2
            elif currArea*2 > totArea:
                extraArea = (currArea*2 - totArea)/float(2)
                return y2 - extraArea/baseLen

        return 0