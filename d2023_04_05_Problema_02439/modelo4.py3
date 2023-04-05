class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        resposta = 0
        anterioresSoma = 0
        for i, v in enumerate (nums):
            anterioresSoma += v
            resposta = max (resposta, (anterioresSoma + i) // (i + 1))
        return resposta
    
