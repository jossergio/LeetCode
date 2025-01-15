class Solution:
    def minimumLength(self, s: str) -> int:
        resposta = len (s)
        for q in Counter (s).values ():
            if q >= 3:
                if q % 2 == 0:
                    q -= 1 # Torna o ímpar menor
                resposta -= q - 1 # Só fica o do meio e tira os outros
        return resposta
    