class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        return [i for i, c in Counter (arr).items () if (c / len (arr)) > 0.25][0] # Segundo o problema, só há um
        
