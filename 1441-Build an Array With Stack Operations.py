class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        res = []
        targetIdx = 0
        for i in range(1, n+1):
            if targetIdx == len(target):
                break
            if i == target[targetIdx]:
                res.append("Push")
                targetIdx += 1            
            else:
                res.append("Push")
                res.append("Pop")

        return res