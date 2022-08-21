class Solution(object):
    def findSmallestRegion(self, regions, region1, region2):
        """
        :type regions: List[List[str]]
        :type region1: str
        :type region2: str
        :rtype: str
        """
        parent = collections.defaultdict(str)
        
        for region in regions:
            for i in range(1, len(region)):
                parent[region[i]] = region[0]
        
        used = set([region1])
        while parent[region1]:
            region1 = parent[region1]
            used.add(region1)
            
        while region2 not in used and parent[region2]:
            region2 = parent[region2]
        
        return region2