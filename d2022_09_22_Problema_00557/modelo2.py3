class Solution:
    def reverseWords(self, s: str) -> str:
        
        return " ".join ([palavra [::-1] for palavra in s.split (" ")])

