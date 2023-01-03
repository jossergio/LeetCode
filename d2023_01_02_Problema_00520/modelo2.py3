class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if len (word) < 2:
            return True # Não há o que fazer
        padrao = word [0].isupper () # Padrão da 1a letra, que será usado no restante
        if (not padrao) and (word [1].isupper ()): # A 1a é minúscula e a 2a já é maiúscula
            return False
        else:
            padrao = word [1].isupper () # Define o Padrao a partir daqui
        for c in word [2:]:
            if not padrao == c.isupper ():
                return False
        return True # Passou e não viu problemas
    
