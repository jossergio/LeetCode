class Solution:
    def longestPalindrome(self, s: str) -> int:
        tmp = set ()
        contador = 0
        for c in s:
            if c in tmp:
                tmp.remove (c)
                contador += 2
            else:
                tmp.add (c)
        return contador if len (tmp) == 0 else contador + 1
    
