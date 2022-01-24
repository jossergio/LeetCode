class Solution:
    def detectCapitalUse(self, word: str) -> bool:

        if len (word) > 1 and word [1:].islower (): # Indiferente se a primeira é ou não
            return True
        
        return word.isupper () or len (word) == 1

