class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        maior = max (candies)
        return [((x + extraCandies) >= maior) for x in candies]

