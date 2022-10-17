class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        letras = set ()
        for c in sentence:
            letras.add (c)
            if len (letras) == 26: # Total de letras do alfabeto inglês; chegou no máximo possível
                return True
        return False # Por omissão, se chegou até aqui

