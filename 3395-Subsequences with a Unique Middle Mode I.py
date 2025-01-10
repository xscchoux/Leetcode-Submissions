class Solution:
    def subsequencesWithMiddleMode(self, nums: List[int]) -> int:
        N = len(nums)
        kMod = pow(10, 9)+7
        rightCnt = Counter(nums)
        leftCnt = Counter()
        res = 0
        for ind, val in enumerate(nums):
            rightCnt[val] -= 1
            left, right = ind, N-ind-1
            tot = comb(left, 2)*comb(right, 2)
            tot -= comb(left-leftCnt[val], 2)*comb(right-rightCnt[val], 2)

            for key in rightCnt|leftCnt:
                if key == val:
                    continue
                # Subtract the cases where there are two modes and both occur 2 times.
                # 221 cases: bb/a/ac, ca/a/bb, bc/a/ab, ab/a/bc, b is the key, c!=a && c!=b
                tot -= comb(leftCnt[key], 2)*rightCnt[val]*(right-rightCnt[val]-rightCnt[key])
                tot -= (left-leftCnt[val]-leftCnt[key])*leftCnt[val]*comb(rightCnt[key], 2)
                tot -= leftCnt[key]*(left-leftCnt[key]-leftCnt[val])*rightCnt[val]*rightCnt[key]
                tot -= leftCnt[val]*leftCnt[key]*rightCnt[key]*(right-rightCnt[val]-rightCnt[key])

                # Subtract the cases where the current mode occurs 2 times but another number occurs 3 times.
                # 32 cases: bb/a/ba, ba/a/bb
                tot -= comb(leftCnt[key], 2)*rightCnt[val]*rightCnt[key]
                tot -= leftCnt[key]*leftCnt[val]*comb(rightCnt[key], 2)

            leftCnt[val] += 1
            res = (res + tot)%kMod


        return res