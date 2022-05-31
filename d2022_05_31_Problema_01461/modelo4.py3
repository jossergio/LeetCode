class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:

        conjunto = set (s [0 + i:i + k] for i in range (0, len (s) - k + 1))
            
        return len (conjunto) == (2 ** k) # Encontrou todos
    
