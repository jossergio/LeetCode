class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted (nums)
        resposta = set ()
        for i, v in enumerate (nums):
            if i > 0 and v == nums [i - 1]: # Evita sequencia similar de cara
                continue
            if v > 0: # Não teremos números negativos para zerar a soma
                break
            j = i + 1
            k = len (nums) - 1
            while j < k:
                if nums [i] + nums [j] + nums [k] == 0:
                    resposta.add ((nums [i], nums [j], nums [k])) # Tupla, já ordenada
                    j += 1
                    k -= 1
                else:
                    if nums [i] + nums [j] + nums [k] > 0:
                        k -= 1
                    else:
                        j += 1
        return [list (a) for a in resposta]
    
