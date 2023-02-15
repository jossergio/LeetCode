class Solution:
    def countOdds(self, low: int, high: int) -> int:
        return len ([x for x in range (low, high + 1) if x % 2 == 1])

