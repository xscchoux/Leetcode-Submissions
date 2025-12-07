class Solution:
    def totalScore(self, hp: int, damage: List[int], requirement: List[int]) -> int:
        N = len(damage)
        arr = SortedList()

        currDamage = 0
        tot = []
        for i in range(N):
            currDamage += damage[i]
            arr.add(currDamage + requirement[i])
            tot.append(currDamage + requirement[i])

        res = 0
        for i in range(N):
            idx = arr.bisect_right(hp)
            res += idx
            hp += damage[i]
            arr.discard(tot[i])
        
        return res
        