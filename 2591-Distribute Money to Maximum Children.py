class Solution:
    def distMoney(self, money: int, children: int) -> int:
        if money < children:
            return -1
        if money > children*8:
            return children-1
        if money == 4 and children == 1:
            return -1

        money -= children
        res, remainder = divmod(money, 7)
        
        if remainder == 3:
            if res > 0 and children - res == 1:
                res -= 1
            
        return res