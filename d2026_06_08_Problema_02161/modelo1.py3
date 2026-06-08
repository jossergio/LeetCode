class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        return \
            [a for a in nums if a < pivot] + \
            [a for a in nums if a == pivot] + \
            [a for a in nums if a > pivot]
    