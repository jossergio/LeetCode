class Solution:
    def reverseWords(self, s: str) -> str:
        
        return " ".join (["".join (reversed (list (palavra))) for palavra in s.split (" ")])

