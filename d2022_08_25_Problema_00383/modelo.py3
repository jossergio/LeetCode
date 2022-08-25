class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        
        tmp = Counter (magazine)
        
        for c in ransomNote:
            if tmp.get (c, 0) == 0:
                return False
            else:
                tmp [c] -= 1
                
        return True
    
