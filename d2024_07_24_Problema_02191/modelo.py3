class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:

        def mapeado (v: int):
            resultado = 0
            p = 0
            while v > 9: # Pois a última parcela será considerada, pois pode vir zero
                resto = v % 10
                resultado += mapping [v % 10] * (10 ** p)
                v //= 10
                p += 1
            resultado += mapping [v] * (10 ** p) # v é algum resto, mesmo que zero
            return resultado

        a = defaultdict (list)
        for n in nums:
            a [mapeado (n)].append (n)
        resposta = list ()
        for i in sorted (a.keys ()):
            resposta.extend (a [i])
        return resposta

