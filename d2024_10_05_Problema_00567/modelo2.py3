class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        t1 = len (s1)
        t2 = len (s2)
        if t1 > t2: # A plataforma gera casos assim
            return False # Não há como ser verdade para esses casos
        d1 = [0] * 26
        d2 = [0] * 26
        ORD_a = ord ('a') # Para ficar constante
        ordem = lambda c: ord (c) - ORD_a
        for i in range (t1):
            d1 [ordem (s1 [i])] += 1
            d2 [ordem (s2 [i])] += 1
        for i in range (t1, t2): # Se t2 < t1, nem executa
            if (d1 == d2):
                return True
            # else
            d2 [ordem (s2 [i - t1])] -= 1
            d2 [ordem (s2 [i])] += 1
        return d1 == d2 # No laço, sobra o último teste
    
