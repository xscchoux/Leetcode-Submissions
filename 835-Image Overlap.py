class Solution(object):
    def largestOverlap(self, img1, img2):
        """
        :type img1: List[List[int]]
        :type img2: List[List[int]]
        :rtype: int
        """
        def getOnes(matrix):
            ans = []
            for r in range(len(matrix)):
                for c in range(len(matrix[0])):
                    if matrix[r][c] == 1:
                        ans.append((r, c))
            return ans
        
        res = 0
        count_one1 = getOnes(img1)
        count_one2 = getOnes(img2)
        
        hmap = collections.defaultdict(int)
        
        for r1, c1 in count_one1:
            for r2, c2 in count_one2:
                dist = (r1-r2, c1-c2)
                hmap[dist] += 1
                res = max(res, hmap[dist])
                
        return res