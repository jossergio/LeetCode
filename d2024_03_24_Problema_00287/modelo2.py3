class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        return [a for a, b in Counter (nums).items () if b > 1][0]

