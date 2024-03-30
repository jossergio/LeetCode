class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        vistos = set ()
        for n in nums:
            if n > 0: # Filtra
                vistos.add (n)
        resposta = 1
        for i in sorted (vistos):
            if resposta != i:
                return resposta
            resposta += 1
        return resposta # É depois dos números


