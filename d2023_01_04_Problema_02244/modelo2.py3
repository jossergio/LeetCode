class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        resposta = 0
        for v in Counter (tasks).values ():
            if v == 1:
                return -1 # Sumariamente
            d, m = divmod (v, 3)
            resposta += d
            if m > 0:
                resposta += 1
        return resposta
    
