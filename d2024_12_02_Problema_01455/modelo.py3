class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        for i, p in enumerate (sentence.split (" ")):
            if p.find (searchWord) == 0:
                return i + 1 # 1-begin
        return -1 # Não havia
    
