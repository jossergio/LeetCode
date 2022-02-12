class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        
        as1 = list (s1)
        as2 = list (s2)
        ts1 = len (as1)
        
        as1.sort ()
        
        for i in range (len (as2) - ts1 + 1):
            tmp = as2 [i:i + ts1]
            tmp.sort ()
            if tmp == as1:
                return True
        return False
        
