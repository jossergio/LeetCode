class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        c1 = defaultdict (int)
        c2 = defaultdict (int)
        contar = 0
        resposta = [0] * len (A)
        for i in range (0, len (A)): # São do mesmo tamanho
            c1 [A [i]] += 1
            c2 [B [i]] += 1
            if A [i] == B [i]:
                contar += 1
            else:
                if c1 [A [i]] == c2 [A [i]]:
                    contar += 1
                if c1 [B [i]] == c2 [B [i]]:
                    contar += 1
            resposta [i] = contar
        return resposta
    