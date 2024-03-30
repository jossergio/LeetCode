class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        return [i for i, v in Counter (nums).items () if v > 1]
    
