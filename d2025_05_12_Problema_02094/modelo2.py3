class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        cont = Counter (digits)
        resposta = list ()
        for n in range (100, 1000, 2):
            tmp, a1 = divmod (n, 10)
            tmp, a2 = divmod (tmp, 10)
            a3 = tmp % 10
            cont [a1] -= 1
            cont [a2] -= 1
            cont [a3] -= 1
            if cont [a1] >= 0 and cont [a2] >= 0 and cont [a3] >= 0: # Mesmo que sejam iguais
                resposta.append (n)
            cont [a1] += 1
            cont [a2] += 1
            cont [a3] += 1
        return resposta
            