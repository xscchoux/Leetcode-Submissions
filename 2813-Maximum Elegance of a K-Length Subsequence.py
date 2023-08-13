class Solution:
    def findMaximumElegance(self, items: List[List[int]], k: int) -> int:
# https://www.youtube.com/watch?v=lGyyyvLY7NI&t=13s&ab_channel=HuifengGuan   
        items.sort(reverse = True)
        profitSum = 0
        cateCount = defaultdict(int)
        pq = []
        
        for i in range(k):
            profitSum += items[i][0]
            cateCount[items[i][1]] += 1
        
        t = len(cateCount)
        res = profitSum + t*t
        ind = k - 1
        
        for i in range(k, len(items)):    
            while ind >= 0 and cateCount[items[ind][1]] == 1:
                ind -= 1
            if items[i][1] not in cateCount:
                if ind >= 0:
                    cateCount[items[ind][1]] -= 1
                    cateCount[items[i][1]] += 1
                    profitSum -= items[ind][0]
                    profitSum += items[i][0]
                    t += 1
                    res = max(res, profitSum + t*t)
                    ind-=1
                else:
                    break
        
        return res