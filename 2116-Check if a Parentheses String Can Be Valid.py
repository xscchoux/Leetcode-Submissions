class Solution(object):
    def canBeValid(self, s, locked):
        """
        :type s: str
        :type locked: str
        :rtype: bool
        """
        if len(s)%2:
            return False
        
# left to right, check if the number of "(" is greater than or equal to the number of ")"
        free = bra = 0
        for i in range(len(s)):
            if locked[i] == "0":
                free += 1
            else:
                if s[i] == ")":
                    if free + bra < 1:
                        return False
                    else:
                        if bra:
                            bra -= 1
                        else:
                            free -= 1
                else:
                    bra += 1
        if bra > free:
            return False
        
# right to left, check if the number of ")" is greater than or equal to the number of "("
        free2 = bra2 = 0
        for i in range(len(s)-1, -1, -1):
            if locked[i] == "0":
                free2 += 1
            else:
                if s[i] == "(":
                    if free2 + bra2 < 1:
                        return False
                    else:
                        if bra2:
                            bra2 -= 1
                        else:
                            free2 -= 1
                else:
                    bra2 += 1
        if bra2 > free2:
            return False
        
        return True