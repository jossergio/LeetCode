class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        return [idx for idx, cont in Counter (nums).items () if cont == 1][0] # Só haverá um, pela definição do problema
    
