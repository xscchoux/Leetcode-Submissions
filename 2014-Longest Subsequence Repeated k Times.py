# O(7*n*(e-1)*m!)
class Solution:
    def longestSubsequenceRepeatedK(self, s: str, k: int) -> str:
        res = ""
        cand = sorted([key for key, val in Counter(s).items() if val >= k], reverse = True)

        q = deque(cand)

        # There are not more than (e - 1) * m! possible subsequences that can be added to the queue,
        # where m = (n / k). To compute this, we sum over all combinations of i elements
        # from m, each multiplied by i!, i.e.:
        #      (e - 1) * m! > sum of C(m, i) * i! for i from 1 to m
        # note that e-1 = 1/1! + 1/2! + 1/3! + ...

        while q:
            curr = q.popleft()
            if len(curr) > len(res):
                res = curr

            for nxtChar in cand:    # O(7)
                nxt = curr + nxtChar
                it = iter(s)
                if all(ch in it for ch in nxt*k):  # O(n)
                    q.append(nxt)
        
        return res