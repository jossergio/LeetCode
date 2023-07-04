class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        conjunto = set (nums)
        qtds = defaultdict (int)
        for v in nums:
            qtds [v] += 1
            if qtds [v] == 3:
                conjunto.remove (v)
        return list (conjunto) [0] # Restará o único
    
