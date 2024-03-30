class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        existe = [False] * (len (nums) + 1) # num é 1-begin
        resposta = []
        for v in nums:
            if existe [v]:
                resposta.append (v) # Só aparece 1 ou duas vezes, se aparecer
            else:
                existe [v] = True
        return resposta
    
