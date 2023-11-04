class Solution:
    def getLastMoment(self, n: int, left: List[int], right: List[int]) -> int:
        return max ((sorted (left)[-1] if len (left) > 0 else 0), ((n - sorted (right)[0]) if len (right) > 0 else 0))
        
