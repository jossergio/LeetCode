class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        contagem = sorted ([a for a in Counter (nums).values ()], reverse = True)
        maximo = contagem [0] # Só para melhorar o visual e o entendimento
        return maximo * len ([a for a in contagem if a == maximo])
