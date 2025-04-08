class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        cont = Counter (nums)
        t = len (nums)
        resposta = 0
        i = 0
        while len ([v for v in cont.values () if v > 1]) > 0:
            limite = i + 3 # i tem contínua atualização
            while i < min (limite, t):
                cont [nums [i]] -= 1
                i += 1
            resposta += 1
        return resposta
    