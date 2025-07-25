class Solution:
    def maxSum(self, nums: List[int]) -> int:
        negativos = set ([a for a in nums if a < 0])
        positivos = set ([a for a in nums if a >= 0])
        if len (positivos) > 0:
            return sum (set (positivos))
        # else
        return max (negativos)
