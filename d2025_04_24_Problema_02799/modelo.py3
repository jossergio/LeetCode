class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        distintos = len (set (nums))
        t = len (nums)
        resposta = 0
        for i in range (t):
            tmp = set ()
            for j in range (i, t):
                tmp.add (nums [j])
                if len (tmp) == distintos:
                    resposta += 1
        return resposta
    