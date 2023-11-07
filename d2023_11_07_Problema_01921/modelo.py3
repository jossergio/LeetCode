class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        t = len (dist) # Tanto faz
        tempos = sorted ([ceil (d / v) for d, v in zip (dist, speed)])
        for k in range (t):
            if tempos [k] <= k:
                return k
        return t

