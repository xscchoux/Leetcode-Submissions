class Solution(object):
    def rankTeams(self, votes):
        """
        :type votes: List[str]
        :rtype: str
        """
# Time O(NM) for iterating
# Time O(MMlogM) for sorting
# Space O(M^2)
# where N = votes.length and M = votes[0].length <= 26
        
        N = len(votes[0])
        hmap = {c: [0]*N + [-ord(c)] for c in votes[0]}
        
        for vote in votes:
            for i, c in enumerate(vote):
                hmap[c][i] += 1

        res = list(votes[0])
        res.sort(key = lambda x: hmap[x], reverse = True)
        
        return "".join(res)