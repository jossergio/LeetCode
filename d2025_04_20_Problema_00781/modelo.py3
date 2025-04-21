class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        cont = Counter (answers)
        resposta = 0
        for r, c in cont.items ():
            total = r + 1
            v = c
            while v > 0:
                resposta += total
                v -= total
        return resposta
    