# O(n*26*2)
class Solution:
    def makeStringGood(self, s: str) -> int:
        count = [0]*26
        mx = 0
        res = math.inf

        for c in s:
            count[ord(c)-ord('a')] += 1
            mx = max(mx, count[ord(c)-ord('a')])

        def cal(target):

            @cache
            def dp(idx, carry):
                if idx == 26:
                    return 0
                res = math.inf
                curr = count[idx]
                if curr == target or curr == 0:
                    return dp(idx+1, 0)
                # delete
                if target > curr:
                    res = min(res, dp(idx+1, 0) + curr)
                else:
                    res = min(res, dp(idx+1, 0) + curr-target)

                # insert (add to target)
                if curr < target:
                    res = min(res, dp(idx+1, 0) + max(0, target-(curr+carry)))

                # update
                if curr < target:
                    res = min(res, dp(idx+1, curr) + curr)

                    # if carry + curr > target:
                    #     res = min(res, dp(idx+1, carry+curr-target) + carry+curr-target) No need to consider this case. This will take the same # of steps if we update curr to target and increase (insert) the next char by carry+curr-target
                    # else:
                    #     res = min(res, dp(idx+1, curr) + curr)
                
                else:
                    res = min(res, dp(idx+1, curr-target) + curr-target)

                return res
            
            ans = dp(0, 0)
            dp.cache_clear()
            return ans


        for mxVal in range(0, mx+1):
            res = min(res, cal(mxVal))
        
        return res