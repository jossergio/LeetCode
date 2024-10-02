class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        rank = {v: i + 1 for i, v in enumerate (sorted (set (arr)))}
        # Tem que ser preparado antes, pois não se conhece cada elemento, ainda
        # O ranking é 1-begin
        return [rank [v] for v in arr]
    
