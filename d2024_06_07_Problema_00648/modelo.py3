class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        palavras = sentence.split (" ")
        
        def radical (p: str) -> str:
            for d in dictionary:
                if len (d) < len (p) and d == p [:len (d)]:
                    p = d
            return p
        
        for i in range (0, len (palavras)):
            palavras [i] = radical (palavras [i])
        return " ".join (palavras)
    
