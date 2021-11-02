class Solution(object):
    def minNumberOfFrogs(self, croakOfFrogs):
        """
        :type croakOfFrogs: str
        :rtype: int
        """
        hmap = collections.defaultdict(int)
        frog = 0
        res = 0
        for s in croakOfFrogs:
            if s == "c":
                frog += 1
                res = max(frog, res)
                hmap["c"] += 1
            elif s == "r":
                hmap["c"] -= 1
                if hmap["c"] < 0:
                    return -1
                hmap["r"] += 1
            elif s == "o":
                hmap["r"] -= 1
                if hmap["r"] < 0:
                    return -1
                hmap["o"] += 1
            elif s == "a":
                hmap["o"] -= 1
                if hmap["o"] < 0:
                    return -1
                hmap["a"] += 1
            elif s == "k":
                hmap["a"] -= 1
                if hmap["a"] < 0:
                    return -1
                frog -= 1
            else:
                return -1
        
        return res if all(x == 0 for x in hmap.values()) else -1