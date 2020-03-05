class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
# my solution
        l, r = 0, len(s)-1
        while l<r:
            while l<=len(s)-1 and not s[l].isalnum():
                l+=1
            while r>=0 and not s[r].isalnum():
                r-=1
            if not l<r:
                return True
            if s[l].lower() == s[r].lower():
                l+=1
                r-=1
            else:
                return False
        return True
        
# another
        if not s.strip():
            return True
        
        s = s.strip()
        s = re.sub('[^a-zA-Z0-9]','',s) 
        l, r = 0, len(s)-1
        while l<r:
            if s[l].lower()!= s[r].lower():
                return False
            else:
                l+=1
                r-=1
        return True