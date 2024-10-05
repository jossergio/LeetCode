class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        t1 = len (s1)
        d1 = dict ()
        d2 = dict ()
        for letra in range (97, 123):
            # Inicializa os dicionários com todas as letras possíveis
            d1 [chr (letra)] = 0
            d2 [chr (letra)] = 0
        d1.update (Counter (s1))
        d2.update (Counter (s2 [:t1])) # Pega os primeiros, baseado no tamanho de s1
        for i in range (t1, len (s2)):
            if (d1 == d2):
                return True
            # else
            d2 [s2 [i - t1]] -= 1
            d2 [s2 [i]] += 1
        return d1 == d2 # No laço, sobra o último teste
    
