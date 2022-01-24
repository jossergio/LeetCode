class Solution:
    def detectCapitalUse(self, word: str) -> bool:

        if len (word) == 1:
            return True

        # Indiferente se a primeira é maiúscula, se o resto é, é válido
        # Ou se todo mundo for maiúscula
        return word [1:].islower () or word.isupper ()

