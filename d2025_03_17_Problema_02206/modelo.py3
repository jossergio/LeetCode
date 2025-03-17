class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        return not ( \
                   len (nums) % 2 == 1 \
                   or len ([a for a in Counter (nums).values () if a % 2 == 1]) > 1)
    