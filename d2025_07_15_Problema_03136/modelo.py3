class Solution:
    def isValid(self, word: str) -> bool:
        if len (word) < 3:
            return False # Sumariamente
        # else
        vogais = set ("aeiouAEIOU")
        consoantes = (set ([chr (a) for a in range (ord ('a'), ord ('z') + 1)]) | \
            set (chr (a) for a in range (ord ('A'), ord ('Z') + 1))) - \
            vogais
        numeros = set ("0123456789")
        w = set (word)
        if len (vogais & w) == 0:
            return False
        # else
        w -= vogais
        if len (consoantes & w) == 0:
            return False
        # else
        w -= consoantes
        w -= numeros
        return len (w) == 0 # Não pode ter sobrado nada
