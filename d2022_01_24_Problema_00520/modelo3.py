class Solution:
    def detectCapitalUse(self, word: str) -> bool:

        if len (word) == 1:
            return True
        if word [0].isupper () and word.isupper ():
                return True
        
        # Indiferente se a primeira é maiúscula, se o resto é, é válido
        return word [1:].islower ()

