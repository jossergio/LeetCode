class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        tmp = [0] * (len (nums) + 1)
        # Tem que desconsiderar o primeiro, que é 0
        tmp [0] = -1
        for v in nums:
            tmp [v] += 1
        resposta = dict ([(v, i) for i, v in enumerate (tmp) if v == 0 or v == 2])
        return [resposta [2], resposta [0]]

