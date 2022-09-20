class Solution(object):
    def findDuplicate(self, paths):
        """
        :type paths: List[str]
        :rtype: List[List[str]]
        """
        hmap = collections.defaultdict(list)
        
        for path in paths:
            arr = path.split()
            for x in arr[1:]:
                file_name, content = x.split("(")
                hmap[content[:-1]].append(arr[0] + "/" + file_name)
                
        res = []
        
        for x in hmap.values():
            if len(x) > 1:
                res.append(x)
        
        return res