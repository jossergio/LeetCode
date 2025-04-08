class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        vistos = set ()
        for i, v in enumerate (reversed (nums)):
            if v in vistos:
                return (len (nums) - i + 2) // 3 # +2 = um por 0-begin e outro pois é a partir do próximo
            # else
            vistos.add (v)
        return 0 # Não há
