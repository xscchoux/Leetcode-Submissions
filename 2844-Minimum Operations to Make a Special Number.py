class Solution:
    def minimumOperations(self, num: str) -> int:
        num = num[::-1]
        res = len(num)
        
        def removed(string):
            a, b = string[0], string[1]
            try:
                ind_b = num.index(b)
                ind_a = num.index(a, ind_b+1)  # If any element which is not present is searched, it raises a ValueError.
                return ind_a-1
            except:
                return len(num)
        
        for string in ("00", "25", "50", "75"):
            res = min(res, removed(string))
            
        if "0" in num:
            return min(res, len(num)-1)
        return res