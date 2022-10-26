class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        tmp = [0] * (len (nums) + 1)
        # O primeiro elemento, posição zero, tem que ser desconsiderado
        tmp [0] = -1 # Um contador inválido
        for v in nums:
            tmp [v] += 1
        resposta = [(v, i) for i, v in enumerate (tmp) if v == 0 or v == 2]
        if resposta [0][0] == 0: # O primeiro contem o faltante
            return [resposta [1][1], resposta [0][1]]
        # else
        return [resposta [0][1], resposta [1][1]]

