class Solution(object):
    def stoneGameIX(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
# https://leetcode.com/problems/stone-game-ix/discuss/1500343/Python3-freq-table
#         hmap = collections.defaultdict(int)
        
#         for stone in stones:
#             hmap[stone%3] += 1
            
#         if hmap[0]%2 == 0:
#             return hmap[1] and hmap[2]
#         else:
#             return abs(hmap[1]-hmap[2])>=3
        
# recursive (very slow but passed)
# https://www.youtube.com/watch?v=8MTch2zTOoY&t=2s&ab_channel=HuifengGuan
        hmap = collections.defaultdict(int)
        for stone in stones:
            hmap[stone%3] += 1
        
        # 0: Alice, 1:Bob
        
        def dfs(count, total, turn):
            if count[0] + count[1] + count[2] == 0:
                if turn:
                    return True
                else:
                    return False
                
            if count[0] > 0:
                count[0] -= 1
                return 1-dfs(count, total, 1-turn)
            
            elif total%3 == 1:
                if count[1] > 0:
                    count[1] -= 1
                    return 1-dfs(count, total+1, 1-turn)
                else:
                    return False
                
            else:  # when total%3 == 2
                if count[2] > 0:
                    count[2] -= 1
                    return 1-dfs(count, total+2, 1-turn)
                else:
                    return False
        
        hmap2 = copy.copy(hmap) # shallow copy of hmap
        
        if hmap[1]:
            hmap[1]-=1
            if 1-dfs(hmap, 1, 1):
                return True

        if hmap2[2]:
            hmap2[2] -= 1
            if 1 - dfs(hmap2, 2, 1):
                return True

        return False