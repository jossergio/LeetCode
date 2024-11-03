class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        palavras = sentence.split ()
        if palavras [0][0] != palavras [-1][-1]:
            return False
        # else
        for p in range (1, len (palavras)):
            if palavras [p][0] != palavras [p - 1][-1]:
                return False
        return True # Passou nos testes
    
