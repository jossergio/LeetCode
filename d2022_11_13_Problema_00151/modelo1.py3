class Solution:
    def reverseWords(self, s: str) -> str:
        # Em uma linha, para embelezar, por Python e para complicar
        return " ".join (reversed ([p for p in s.split (' ') if len (p) > 0]))
        
