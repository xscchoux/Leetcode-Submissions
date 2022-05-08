class Solution(object):
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        count = 0
        for i in range(len(points)):
            hmap = collections.defaultdict(int)
            for j in range(len(points)):
                if i != j:
                    dt = pow(points[i][0]-points[j][0], 2) + pow(points[i][1]-points[j][1], 2)
                    count += hmap[dt]   
                    hmap[dt] += 1
                    
        return 2*count