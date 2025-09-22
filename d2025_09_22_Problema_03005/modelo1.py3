class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        grupos = defaultdict (int)
        maximo = 0
        for v in Counter (nums).values ():
            grupos [v] += 1
            if v > maximo:
                maximo = v
        return grupos [maximo] * maximo
