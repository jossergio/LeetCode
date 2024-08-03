class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        valores = defaultdict (int)
        for a in target:
            valores [a] += 1
        for a in arr:
            valores [a] -= 1
        return len ([a for a, b in valores.items () if b != 0]) == 0
    
