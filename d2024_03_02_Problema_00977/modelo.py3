class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        return sorted ([a * a for a in nums])
        
