class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        d1 = defaultdict (set)
        d2 = defaultdict (set)
        t = len (s1) # Tanto faz
        diferentes = 0
        for i in range (t):
            d1 [s1 [i]].add (i)
            d2 [s2 [i]].add (i)
            if s1 [i] != s2 [i]:
                diferentes += 1
                if diferentes > 2: # O máximo possível
                    return False
        if diferentes == 0:
            return True # São iguais
        if diferentes != 2:
            return False # Não contém um par ou um par único
        diferentes = 0 # Reaproveita
        for i, l in d1.items ():
            if len (l) != len (d2 [i]):
                return False # Há faltantes
            # else
            if l != d2 [i]:
                if len (l ^ d2 [i]) == 2:
                    diferentes += 1
                if diferentes > 2: # O máximo possível
                    return False
        return diferentes == 2 # Há um par e único
        