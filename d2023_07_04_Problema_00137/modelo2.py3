class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        qtds = defaultdict (int)
        for v in nums:
            qtds [v] += 1
        return [i for i, v in qtds.items () if v == 1] [0] # Restará o único
    
