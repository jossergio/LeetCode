class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        c1 = defaultdict (int)
        c2 = defaultdict (int)
        contar = 0
        resposta = [0] * len (A)
        for i, z in enumerate (zip (A, B)):
            a, b = z
            c1 [a] += 1
            c2 [b] += 1
            if a == b:
                contar += 1
            else:
                if c1 [a] == c2 [a]:
                    contar += 1
                if c1 [b] == c2 [b]:
                    contar += 1
            resposta [i] = contar
        return resposta
    