class Solution:
    def maximumWeight(self, intervals: List[List[int]]) -> List[int]:
        N = len(intervals)
        intervals = sorted((*x, i) for (i, x) in enumerate(intervals))

        @cache
        def dp(idx, remain):
            if idx == N or remain == 0:
                return 0, []
            
            # skip
            val, res = dp(idx+1, remain)
            # include
            l, r, w, index = intervals[idx]
            nxtIdx = bisect_left(intervals, r+1, key = lambda x:x[0])
            vv, rr = dp(nxtIdx, remain-1)
            vv += w
            # By creating a copy of rr with rr[:], any modifications to rr (e.g., inserting index using insort
            # are applied only to the copy and not to the original list stored in the cache.
            rr = rr[:]
            insort(rr, index)
            if vv > val or (vv == val and rr < res):
                val = vv
                res = rr
            return val, res

        return dp(0, 4)[1]