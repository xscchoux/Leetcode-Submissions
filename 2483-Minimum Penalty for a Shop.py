class Solution:
    def bestClosingTime(self, customers: str) -> int:
        
# two-pass
        N = len(customers)
        Ycount = customers.count("Y")
        
        smallest = Ycount
        res = 0
        currPenalty = 0
        
        for i in range(N):
            if customers[i] == "N":
                currPenalty += 1
            else:
                Ycount -= 1
            
            if currPenalty + Ycount < smallest:
                smallest = currPenalty + Ycount
                res = i + 1
        
        return res
    
# better two-pass
        N = len(customers)
        currPenalty = customers.count("Y")
        
        smallest = currPenalty
        res = 0
        
        for i in range(N):
            if customers[i] == "N":
                currPenalty += 1
            else:
                currPenalty -= 1
            
            if currPenalty < smallest:
                smallest = currPenalty
                res = i + 1
        
        return res
    
# one-pass
        N = len(customers)
        res = 0
        currPenalty = smallest = 0
        
        for i in range(N):
            if customers[i] == "N":
                currPenalty += 1
            else:
                currPenalty -= 1
            
            if currPenalty < smallest:
                smallest = currPenalty
                res = i + 1
        
        return res