class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        maior = max (candies)
        return map (lambda x: (x + extraCandies) >= maior, candies)
    
