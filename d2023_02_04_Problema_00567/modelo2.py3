class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        
        c = Counter (s1)
        ts1 = len (s1)
        
        for i in range (len (s2) - ts1 + 1):
            if Counter (s2 [i:i + ts1]) == c:
                return True
        return False
    
