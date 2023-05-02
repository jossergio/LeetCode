class Solution:
    def arraySign(self, nums: List[int]) -> int:
        sinal = 1 # Pressupõe
        for v in nums:
            if v == 0:
                return 0
            # else
            if v < 0:
                sinal *= -1
        return sinal
    
