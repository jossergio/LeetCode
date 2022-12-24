class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted (nums)
        resposta = set ()
        for i in range (len (nums)):
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
    
